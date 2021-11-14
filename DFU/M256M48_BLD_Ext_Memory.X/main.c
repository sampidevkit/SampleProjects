#include "libcomp.h"

int main(void)
{
    SYSTEM_Initialize();
    BootLoader_Initialize();

    while(1)
        BootLoader_Tasks();

    return 1;
}