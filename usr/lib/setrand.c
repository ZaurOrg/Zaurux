#include "exio.h"
#include <stdlib.h>
#include <time.h>
int
setrand(int max, int min)
{
  srand(time(NULL));
  srand(rand()%max+min);
  return rand()%max+min;
}
