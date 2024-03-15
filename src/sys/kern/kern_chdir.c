#include "syscall.h"
void chdir(char *path)
{
    asm volatile
    (
        "mov $6, %%eax\n\t"
        "mov %0, %%ebx\n\t"
        "int $0x80\n\t"
        "mov %%eax, %1"
        : "=r" (path)
        : "r" (path)
        : "%eax", "%ebx"
    );
}