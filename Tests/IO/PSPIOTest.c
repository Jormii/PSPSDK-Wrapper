#include <pspkernel.h>
#include <string.h>
#include <stdio.h>

#include "../../common/callback.h"
#include "../../PSPDebug/PSPDebug.h"
#include "../../PSPInput/PSPInput.h"
#include "../../PSPIO/PSPIO.h"

PSP_MODULE_INFO("PSPIOTest", PSP_MODULE_USER, 1, 1);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

const char *dir = "test_dir/";
const char *file = "test_file.txt";
const char *renamed_file = "renamed_file.txt";

void create_and_write_file(const char *path)
{
    PSPFileDescriptor file = PSP_open_file(path, PSP_O_WRONLY | PSP_O_CREAT, 0777);
    char *string = "Text file test";
    size_t string_length = strlen(string);
    PSP_write(file, string, string_length);
    PSP_close_file(file);
}

int main()
{
    init_debug();
    init_input();
    setupExitCallback();

    debug_print("[ Debug ]\n\n");

    create_and_write_file(file);
    PSP_rename_file(file, "renamed_file.txt");
    create_and_write_file(file);

    PSP_mkdir("./test_dir/", 777);
    PSP_change_working_directory("./test_dir/");
    create_and_write_file(file);

    PSP_change_working_directory("./..");
    PSP_remove_dir("./test_dir/");
    PSP_remove_file("./renamed_file.txt");

    debug_print("Press X to quit");

    while (isRunning())
    {
        update_input();

        if (get_button_down(CROSS_BUTTON))
        {
            break;
        }
    }

    sceKernelExitGame();
    return 0;
}