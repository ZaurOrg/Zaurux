#include <stdio.h>
#include <string.h>
#include "exio.h"
void getin(char *s)
{
  fgets(s, sizeof(s)-1, stdin);
  s[strlen(s) - 1] = '\0';
}
