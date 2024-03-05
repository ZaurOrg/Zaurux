#include <stdio.h>

int main(int argc, char **argv)
{
  if (argc < 4)
  {
    int c;
    FILE *f;
    f = fopen(argv[1], "r");
    if (!f)
      {
        puts("Error! No such file!\n");
        return (0);
      }
    while ((c = getc(f)) != EOF)
     {
       putchar(c);
     }
    fclose(f);
    c = 0;
    putchar('\n');
  }
  else if (argv[2][0] == '>' && argc == 4)
  {
    int c;
    FILE *f;
    f = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "w");
    if (!f)
      {
        printf("Error! No such file!\n");
        fclose(f);
        return -1;
      }
    if (!f2)
      {
        printf("Error! No such file!\n");
        fclose(f);
        return -1;
      }
    if (!f && !f2)
      {
        printf("Error! Both files doesn't exist!\n");
        fclose(f);
        fclose(f2);
        return -2;
      }
    while ((c = getc(f)) != EOF)
      {
        if (f2 != fopen("/dev/null", "w"))
          putc(c, f2);
      }
    fclose(f);
    fclose(f2);
    c = 0;
    putchar('\n');
  }
  else
  {
    printf("You forgot to put '>' before the file name.\n");
    return -1;
  }
  return 0;
}