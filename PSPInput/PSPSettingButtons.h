#ifndef PSP_SETTING_BUTTONS_H
#define PSP_SETTING_BUTTONS_H

#include <pspctrl.h>

#define DISC_PRESENT PSP_CTRL_DISC;
#define MEMORY_STICK_PRESENT PSP_CTRL_MS;

typedef enum PSPSettingButton
{
    HOME_BUTTON = PSP_CTRL_HOME,
    SCREEN_BUTTON = PSP_CTRL_SCREEN,
    MUSIC_NOTE_BUTTON = PSP_CTRL_NOTE,
    VOLUME_UP_BUTTON = PSP_CTRL_VOLUP,
    VOLUME_DOWN_BUTTON = PSP_CTRL_VOLDOWN,
    HOLD_SLIDER = PSP_CTRL_HOLD,
    WLAN_SLIDER = PSP_CTRL_WLAN_UP,
} PSPSettingButton;

typedef struct PSPSettingButtonsData
{
    unsigned int settingButtonsPressed;
} PSPSettingButtonsData;

#endif