#include <pspkernel.h>

#include "../../common/callbacks.h"
extern "C"
{
#include "../../PSPDebug/PSPDebug.h"
}

#define VERS 1
#define REVS 0

PSP_MODULE_INFO("HelloWorld", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

class PSPHelloWorld
{
private:
public:
    PSPHelloWorld();
    ~PSPHelloWorld();

    void Print();
};

PSPHelloWorld::PSPHelloWorld()
{
}

PSPHelloWorld::~PSPHelloWorld()
{
}

void PSPHelloWorld::Print()
{
    debug_print("Hello world C++\n");
    debug_print("~ PSPWrapper\n");
}

int main(void)
{
    init_debug();
    setupCallbacks();

    PSPHelloWorld hello_world;
    hello_world.Print();

    while (running())
    {
    }

    sceKernelExitGame();

    return 0;
}