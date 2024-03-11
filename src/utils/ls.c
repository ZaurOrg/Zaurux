#include <dirent.h>
#include <stdio.h>
#include <unistd.h>


int ls(char*, int, int);
int ls(path, a, b)
char *path;
int a;
int b;
{
  struct dirent *d;
  DIR *dh = opendir(path);
  if (!dh)
    {
      perror("Directory doesn't exist\n");
    }
  else
    {
      while ((d = readdir(dh)) != NULL)
        {
                if (!a && d->d_name[0] == '.')
                        continue;
                  printf("%s  ", d->d_name);
                if(b) printf("\n");
        }
    }
}
main(argc, argv)
int argc;
char **argv;
{
  if (argv[0][0] == '\0')
    argv[0][0] = '.';
  ls(argv[1], 0, 0);
}