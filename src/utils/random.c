#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
  puts("\t\tRandom numbers\n\t\tv0.0.1\n");
  srand(time(NULL));
  srand(rand()%rand()%100 + 1);
  for (int i = 0; i < rand()%100 + 1; i++)
    {
      printf("%d ", rand()%100 + 1);
    }
  putchar('\n');
  return (0);
}
