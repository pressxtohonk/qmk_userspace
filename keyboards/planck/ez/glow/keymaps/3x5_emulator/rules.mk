# Firmware size optimization (https://docs.qmk.fm/#/squeezing_avr)
LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no
MUSIC_ENABLE = no
LEADER_ENABLE = no

EXTRAFLAGS += -flto
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX = no

# Selectively enable features
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes

ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif
