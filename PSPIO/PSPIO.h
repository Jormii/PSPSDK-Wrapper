#ifndef PSP_IO_H
#define PSP_IO_H

typedef int PSPFileDescriptor;
typedef int PSPAccessMode;

PSPFileDescriptor psp_stdin();
PSPFileDescriptor psp_stdout();
PSPFileDescriptor psp_stderr();

PSPFileDescriptor PSP_open_file(const char *file_path, int flags, PSPAccessMode mode);
int PSP_close_file(PSPFileDescriptor file);
int PSP_read(PSPFileDescriptor file, void *data, unsigned long size);
int PSP_write(PSPFileDescriptor file, void *data, unsigned long size);

int PSP_change_working_directory(const char *path);
int PSP_rename_file(const char *file, const char *new_file_name);
int PSP_mkdir(const char *path, PSPAccessMode mode);
int PSP_remove_file(const char *file_name);
int PSP_remove_dir(const char *path);

#endif