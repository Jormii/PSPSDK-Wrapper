#ifndef PSP_SETTING_BUTTONS_H
#define PSP_SETTING_BUTTONS_H

#define DISC_PRESENT 0x1000000;
#define MEMORY_STICK_PRESENT 0x2000000;

typedef enum PSPSettingButton
{
    HOME_BUTTON = 0x010000,
    SCREEN_BUTTON = 0x400000,
    MUSIC_NOTE_BUTTON = 0x800000,
    VOLUME_UP_BUTTON = 0x100000,
    VOLUME_DOWN_BUTTON = 0x200000,
    HOLD_SLIDER = 0x020000,
    WLAN_SLIDER = 0x040000,
} PSPSettingButton;

typedef struct PSPSettingButtonsData
{
    unsigned int setting_buttons_pressed;
} PSPSettingButtonsData;

#endif