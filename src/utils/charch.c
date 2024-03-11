#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  for (int i = 0; i < strlen(argv[1]); i++)
    {
      if (argv[1][i] == argv[2][0])
        argv[1][i] = argv[3][0];
    }
  puts(argv[1]);
  return (0);
}
