#include <stdio.h>
#include "syscall.h"
void
panic(const char *s)
{
  printf("panic: %s\n", s);
  for (;;);
}