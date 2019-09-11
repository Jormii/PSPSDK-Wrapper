#include <pspiofilemgr.h>

#include "./PSPIO.h"

PSPFileDescriptor PSP_open_file(const char *file_path, int flags, PSPAccessMode mode)
{
    return sceIoOpen(file_path, flags, mode);
}

int PSP_close_file(PSPFileDescriptor file)
{
    return sceIoClose(file);
}

int PSP_read(PSPFileDescriptor file, void *data, unsigned long size)
{
    return sceIoRead(file, data, size);
}

int PSP_write(PSPFileDescriptor file, void *data, unsigned long size)
{
    return sceIoWrite(file, data, size);
}

int PSP_change_working_directory(const char *path)
{
    return sceIoChdir(path);
}

int PSP_rename_file(const char *file, const char *new_file_name)
{
    return sceIoRename(file, new_file_name);
}

int PSP_mkdir(const char *path, PSPAccessMode mode)
{
    return sceIoMkdir(path, mode);
}

int PSP_remove_file(const char *file_name)
{
    return sceIoRemove(file_name);
}

int PSP_remove_dir(const char *path)
{
    return sceIoRmdir(path);
}