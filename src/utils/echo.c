
#include <stdio.h>
int main(int argc, char **argv)
{
  if (argc < 3)
    printf("%s\n", argv[1]);
  else if (argv[2][0] == '>')
    {
      FILE *f = fopen(argv[3], "w");
      fprintf(f, argv[1]);
      fclose(f);
    }
  else
    {
      printf("You forgot to put '>' before the file name.\n");
      return -1;
    }
  return 0;
}