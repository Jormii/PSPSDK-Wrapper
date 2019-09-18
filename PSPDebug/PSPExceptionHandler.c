#include "../PSPIO/PSPIO.h"
#include "./PSPExceptionHandler.h"

static void *default_error_handler(PspDebugRegBlock *regs);

static void *default_error_handler(PspDebugRegBlock *regs)
{
    PSPFileDescriptor errorFileDescriptor;
}

void psp_initialize_exception_handler()
{
}

int psp_get_stack_trace(PspDebugRegBlock *regs, PspDebugStackTrace *trace, int maxTraces)
{
}

int psp_hook_error_handler(PspDebugErrorHandler handler)
{
    pspDebugInstallErrorHandler(handler);
}

void psp_breakpoint_exception()
{
    pspDebugBreakpoint();
}