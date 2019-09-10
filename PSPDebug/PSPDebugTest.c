#include <pspkernel.h>
#include <pspdisplay.h>

#include "../common/callback.h"
#include "../PSPInput/PSPInput.h"
#include "./PSPDebug.h"

#define VERS 1 //Talk about this
#define REVS 0

PSP_MODULE_INFO("PSPDebugTest", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

void print_debug_text()
{
    debug_print("[ DEBUG ]\n\n");
    debug_print("I'd just like to interject for a moment. What you're referring to as Linux, is in fact, GNU/Linux, or as I've recently taken to calling it, GNU plus Linux. Linux is not an operating system unto itself, but rather another free component of a fully functioning GNU system made useful by the GNU corelibs, shell utilities and vital system components comprising a full OS as defined by POSIX.\n\n");
    debug_print("Many computer users run a modified version of the GNU system every day, without realizing it. Through a peculiar turn of events, the version of GNU which is widely used today is often called \"Linux\", and many of its users are not aware that it is basically the GNU system, developed by the GNU Project.\n\n");
    debug_print("There really is a Linux, and these people are using it, but it is just a part of the system they use. Linux is the kernel: the program in the system that allocates the machine's resources to the other programs that you run. The kernel is an essential part of an operating system, but useless by itself; it can only function in the context of a complete operating system. Linux is normally used in combination with the GNU operating system: the whole system is basically GNU with Linux added, or GNU/Linux. All the so-called \"Linux\" distributions are really distributions of GNU/Linux.\n\n");
    debug_print("\n");
}

int main(void)
{
    init_debug();
    init_input();
    setupExitCallback();

    print_debug_text();
    while (isRunning())
    {
        update_input();
        if (get_button_down(TRIANGLE_BUTTON))
        {
            set_background_color(255, 255, 255);
            print_debug_text();
        }
        if (get_button_down(SQUARE_BUTTON))
        {
            set_background_color(255, 0, 0);
            print_debug_text();
        }
        if (get_button_down(CROSS_BUTTON))
        {
            set_background_color(0, 255, 0);
            print_debug_text();
        }
        if (get_button_down(CIRCLE_BUTTON))
        {
            set_background_color(0, 0, 255);
            print_debug_text();
        }

        if (get_button_down(L_TRIGGER))
        {
            debug_print("HOLA\n");
        }
    }

    sceKernelExitGame();

    return 0;
}
