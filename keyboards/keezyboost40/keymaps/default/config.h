/*
This is the c configuration file for the keymap

Copyright 2023 Mitchell Kwong

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// Firmware size optimization (https://docs.qmk.fm/#/squeezing_avr)
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
// #define NO_ACTION_ONESHOT
// #define NO_ACTION_TAPPING
#define LAYER_STATE_8BIT
#define NO_MUSIC_MODE

// Home row mods
#define PERMISSIVE_HOLD // "Nested" taps trigger modifiers
#define QUICK_TAP_TERM 0 // Disables auto repeat on held double taps
#define TAPPING_TERM 160

// Combos
#define COMBO_TERM 20 // Default: 50ms

// Caps word
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define TAPPING_TERM_PER_KEY // Custom double tap speed

// Leader key
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250
