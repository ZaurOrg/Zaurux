#include <sys/types.h>
#include <stdio.h>
#include "syscall.h"
int waitpid(int pid, int *status, int options)
{
    asm volatile
    (
        "mov $5, %%eax\n\t"
        "mov %0, %%ebx\n\t"
        "mov %1, %%ecx\n\t"
        "mov %2, %%edx\n\t"
        "int $0x80\n\t"
        "mov %%eax, %3"
        : "=r" (*status)
        : "r" (pid), "r" (options), "r" (status)
        : "%eax", "%ebx", "%ecx", "%edx"
    );
}