#include <stdio.h>
#include <string.h>
#include "exio.h"
void agets_s(char *s)
{
  gets_s(s, sizeof(s)-1);
  return;
}
