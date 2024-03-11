
#include <stdio.h>
#include "../../include/syscall.h"
panic_t
panic(const char *s)
{
  printf("panic: %s\n", s);
  for (;;);
}