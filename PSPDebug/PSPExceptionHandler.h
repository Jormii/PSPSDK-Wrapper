#ifndef PSP_EXCEPTION_HANDLER_H
#define PSP_EXCEPTION_HANDLER_H

#include "pspdebug.h" // Remove somehow

void psp_initialize_exception_handler();
int psp_get_stack_trace(PspDebugRegBlock *regs, PspDebugStackTrace *trace, int maxTraces);
int psp_hook_error_handler(PspDebugErrorHandler handler);
void psp_breakpoint_exception();

#endif