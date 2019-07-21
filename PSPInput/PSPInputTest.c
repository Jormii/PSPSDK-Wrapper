#include <pspkernel.h>
#include <pspdebug.h>

#include "../common/callback.h"
#include "./PSPInput.h"

PSP_MODULE_INFO("Button Input", PSP_MODULE_USER, 1, 1);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

#define printf pspDebugScreenPrintf

int main()
{
    pspDebugScreenInit();
    setupExitCallback();

    pspDebugScreenSetXY(1, 1);
    printf("[ DEBUG ]\n\n");

    initInput(ANALOG_SAMPLING);
    updateInput();
    if (discIsPresent())
    {
        printf("DISC_IS_PRESSENT\n");
    }
    if (memoryStickIsConnected())
    {
        printf("MEMORY_STICK_CONNECTED\n");
    }
    while (isRunning())
    {
        updateInput();

        if (buttonIsPressed(START_BUTTON))
        {
            printf("START_BUTTON\n");
        }
        if (buttonIsPressed(SELECT_BUTTON))
        {
            printf("SELECT_BUTTON\n");
        }
        if (buttonIsPressed(UP_BUTTON))
        {
            printf("UP_BUTTON\n");
        }
        if (buttonIsPressed(RIGHT_BUTTON))
        {
            printf("RIGHT_BUTTON\n");
        }
        if (buttonIsPressed(DOWN_BUTTON))
        {
            printf("DOWN_BUTTON\n");
        }
        if (buttonIsPressed(LEFT_BUTTON))
        {
            printf("LEFT_BUTTON\n");
        }
        if (buttonIsPressed(TRIANGLE_BUTTON))
        {
            printf("TRIANGLE_BUTTON\n");
        }
        if (buttonIsPressed(CIRCLE_BUTTON))
        {
            printf("CIRCLE_BUTTON\n");
        }
        if (buttonIsPressed(CROSS_BUTTON))
        {
            printf("CROSS_BUTTON\n");
        }
        if (buttonIsPressed(SQUARE_BUTTON))
        {
            printf("SQUARE_BUTTON\n");
        }
        if (buttonIsPressed(L_TRIGGER))
        {
            printf("L_TRIGGER\n");
        }
        if (buttonIsPressed(R_TRIGGER))
        {
            printf("R_TRIGGER\n");
        }

        if (settingButtonIsPressed(HOME_BUTTON))
        {
            printf("HOME_BUTTON\n");
        }
        if (settingButtonIsPressed(SCREEN_BUTTON))
        {
            printf("SCREEN_BUTTON\n");
        }
        if (settingButtonIsPressed(MUSIC_NOTE_BUTTON))
        {
            printf("MUSIC_NOTE_BUTTON\n");
        }
        if (settingButtonIsPressed(VOLUME_UP_BUTTON))
        {
            printf("VOLUME_UP_BUTTON\n");
        }
        if (settingButtonIsPressed(VOLUME_DOWN_BUTTON))
        {
            printf("VOLUME_DOWN_BUTTON\n");
        }
    }

    sceKernelExitGame();
    return 0;
}