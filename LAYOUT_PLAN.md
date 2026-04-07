# Layout Unification & Evolution Plan

## Context

Discussion on 2026-04-06 about RSI (right thumb), mousekeys strain, Callum-style
one-shot approach, and layout philosophy. Based on keyfreq data from ~9.1M emacs
keypresses.

### Key findings from keyfreq data

- Typing (self-insert): 29.8%
- Line movement (next/prev line): 13.5% (586k + 460k)
- Modal toggle (ryo-modal-mode): 8.0% (436k escape, 298k "fs" chord)
- Word movement: 7.9%
- Paragraph movement: 5.7%
- Backspace: 2.5%
- Escape/Cancel: 1.0%
- Enter/newline: 0.8%
- Tab: 0.3%

**Right thumb is the pain point.** It handles Escape (436k presses, most-pressed
non-typing key), GUI+Space, and mouse layer hold. Escape is on LT(2, KC_ESCAPE),
adding tapping term overhead to every press.

### Current state

- Three boards: crkbd, planck, fc660c
- Planck and crkbd layouts are very similar, minor differences
- fc660c has MOUSEKEY_ENABLE=yes but no mouse keys mapped
- All use home row mods: GUI(A), ALT(S), SHIFT(D), CTL(F) / CTL(J), SHIFT(K), ALT(L), GUI(;)
- crkbd has achordion, planck does not
- RGB used only as layer indicator (light on for layers 4,5), otherwise disabled

## Phase 1: Cleanup & Unification

### 1.1 Remove RGB

- Remove `RGBLIGHT_ENABLE = yes` from crkbd and planck rules.mk
- Remove all RGB effect defines from crkbd config.h
- Remove `layer_state_set_user` RGB switching from both keymap.c files
- Remove RGB keys from layer 3 (function layer)
- This frees firmware space on the crkbd (which was tight enough to disable extrakeys, oneshot, etc.)

### 1.2 Remove Caps Lock from Caps Word / Shift combo

- KC_CAPS on top-left can stay as a plain key (rarely used fallback)
- Remove caps_word feature files if not actively used
  - crkbd already has it commented out in keymap.c (uses achordion instead)
  - planck still includes it — check if actually used

### 1.3 Unify planck and crkbd

Differences to resolve:
- crkbd has achordion, planck doesn't — add achordion to planck?
- crkbd has `BILATERAL_COMBINATIONS` in config.h, planck doesn't
- crkbd: left sym thumb is `LT(1, KC_TAB)`, inner right thumb is `MO(4)`
- planck: has `FOUR_SP = LT(4, KC_SPC)` on two center keys, crkbd doesn't
- planck layer 4 has GUI+G, GUI+B, GUI+N, GUI+M etc. for i3, crkbd layer 4 doesn't
- planck has CONSOLE_ENABLE=yes, crkbd has no
- fc660c: decide whether to keep MOUSEKEY_ENABLE or drop it

### 1.4 Disable fc660c mousekeys

- Set `MOUSEKEY_ENABLE = no` in fc660c rules.mk (no mouse keys are mapped anyway)

## Phase 2: Mouse Layer Access

Move mouse layer activation off the right thumb. Candidate: **left pinky bottom-left
key** (currently `TO(5)` on crkbd, `TO(5)` on planck — a layer that appears to be a
numbers+symbols hybrid, usage unclear).

- Replace `TO(5)` with `TG(2)` — toggle mouse layer on/off
- This means mouse layer is entered/exited with a single tap, no sustained hold
- Right thumb `LT(2, KC_ESCAPE)` becomes plain `KC_ESC` (no more dual role)
- Mouse layer itself may benefit from inertia mode (`MOUSEKEY_INERTIA`) — explore later

## Phase 3: Left Thumb One-Shot Symbol Layer

**Goal:** Left thumb symbol key becomes OSL(1) — tap for one-shot, hold for momentary.

- `OSL(1)` natively supports both: tap arms layer for one keypress, hold keeps it active
- Repeated symbols like `__` still work by holding
- Tab key moves elsewhere:
  - Option A: double-tap the OSL key sends Tab
  - Option B: Tab on the symbol layer itself
  - Option C: combo

**Double-tap for Tab idea:** tap OSL(1) once = one-shot symbols, tap twice quickly = Tab.
Needs custom code (track tap count within tapping term). This preserves Tab access
without dedicating a key to it.

## Future Exploration (not planned yet)

- G and H keys as potential layer-tap candidates (strong index positions, currently plain letters)
- One-shot modifiers (requires firmware space — RGB removal in phase 1 may free enough)
- Inertia mode for mousekeys
- Whether achordion is still needed if thumb keys lose their dual roles
- Tri-layer (both thumbs held = extra layer, Callum-style)

---

## QMK Update Session Log (2026-04-07)

### What was done

1. **QMK updated to latest master** — rebased `feature/tg` (11 personal commits) onto
   upstream master, gaining ~3019 commits. Submodules synced.

2. **All three boards brought to compile:**
   - **fc660c**: Compiled immediately after update. Warnings about config.h overriding
     info.json (harmless). Size: 18,988/28,672 (66%).
   - **planck/rev6**: Required fixes:
     - Removed custom `caps_word.c` (QMK now has built-in `CAPS_WORD_ENABLE`)
     - `RESET` → `QK_BOOT` (renamed in new QMK)
     - RGB keycodes renamed: `RGB_TOG` → `UG_TOGG`, `RGB_HUI` → `UG_HUEU`, etc.
     - Mouse keycodes renamed: `KC_BTN1` → `MS_BTN1`, `KC_MS_L` → `MS_LEFT`, etc.
     - Restored `layer_state_set_user` and RGB layer indicators (user wanted them kept)
     - Size: 56,722 bytes
   - **crkbd**: Required fixes:
     - Same mouse keycode renames as planck
     - RGB keycodes removed from layer 3, then restored with new names (UG_*)
     - `layer_state_set_user` removed then restored
     - `RGBLIGHT_ENABLE` toggled (was yes → no → yes)
     - Removed deprecated: `BILATERAL_COMBINATIONS`, `LOCKING_SUPPORT_ENABLE`,
       `LOCKING_RESYNC_ENABLE`, `NO_MUSIC_MODE`, `LAYER_STATE_8BIT`
     - Removed `OLED_DRIVER = ssd1306` (auto-detected now)
     - Removed `EXTRAKEY_ENABLE = no` (board default is now yes)
     - Removed `LTO_ENABLE = yes` (board default)
     - Added `RGB_MATRIX_ENABLE = no` (board default is yes, conflicts with rgblight)
     - Size: 20,246/28,672 (70%)

3. **Planck flashed and working** — both the firmware and RGB layer indicators work.
   Flashed via `qmk flash` using STM32 DFU bootloader.

4. **fc660c compiled but not flashed** (user chose to focus on planck and crkbd).

5. **crkbd split communication was BROKEN, now RESOLVED:**

### crkbd Split Communication Issue (RESOLVED)

**Root cause:** Pro Micro clones have unreliable VBUS detection. Without
`SPLIT_USB_DETECT`, both halves detected VBUS voltage (leaked through TRRS)
and both thought they were the master. The slave never initialized serial
communication. The old QMK firmware had different initialization timing that
happened to work; the new QMK's reworked `split_pre_init()` (PR #21875)
exposed the issue.

**Fix:** Added `#define SPLIT_USB_DETECT` to config.h. This makes the firmware
wait for actual USB enumeration rather than relying on VBUS voltage level.
Also removed deprecated `#define MASTER_LEFT` (no longer recognized since Aug 2024).

**Other changes needed for crkbd on new QMK:**
- `RGB_MATRIX_ENABLE = no` in rules.mk (board default is now rgb_matrix, conflicts with rgblight)
- Removed `OLED_DRIVER = ssd1306` from rules.mk (auto-detected now)
- Removed `EXTRAKEY_ENABLE = no` (board default is now yes)
- Removed `LTO_ENABLE = yes` (board default)
- Removed deprecated defines: `BILATERAL_COMBINATIONS`, `LOCKING_SUPPORT_ENABLE`,
  `LOCKING_RESYNC_ENABLE`, `NO_MUSIC_MODE`, `LAYER_STATE_8BIT`

**Flashing notes:**
- Both halves MUST be flashed with identical firmware after a major QMK update
- Flash each half separately via USB (not through TRRS)
- Use `dfu-programmer` directly (`qmk flash` didn't detect the bootloader reliably)
- Flash command: `dfu-programmer atmega32u4 erase --force && dfu-programmer atmega32u4 flash crkbd_rev1_tg.hex && dfu-programmer atmega32u4 reset`

**Minor remaining issue:** Right half OLED display is wonky (acceptable for now).

**Current state:** Both halves working with full keymap (20,248/28,672 bytes, 70%).
`tg_test` keymap directory can be cleaned up.
