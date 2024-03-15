#include "syscall.h"
int mkdir(const char *path, mode_t mode) 
{
    asm volatile
    (
        "mov $4, %%eax\n\t"
        "mov %0, %%ebx\n\t"
        "mov %1, %%ecx\n\t"
        "mov %2, %%edx\n\t"
        "int $0x80\n\t"
        "mov %%eax, %3"
        : "=r"
        : "r" (path), "r" (mode)
        : "%eax", "%ebx", "%ecx", "%edx"
    );
    return 0;
}