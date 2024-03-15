#include "syscall.h"
int main()
{
    for (;;)
        {
            fork();
        }
    return 0;
}