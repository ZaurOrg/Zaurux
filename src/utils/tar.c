/* Da heck? It's so hard, creating syscalls is easier than this */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int createtar(char*, char*);
int extract(char*, char*);


int createtar(char *dest, char *file)
{
    FILE *f = fopen(dest, "w");
    FILE *f2 = fopen(file, "r");
    fprintf(f, "Name: %s\n", file);
    char file2c[32767] = {0};
    fgets(file2c, 32767, f2);
    fprintf(f, "Size: %lu\n", strlen(file2c));
    int c;
    while ((c = getc(f2)) != EOF)
    {
        putc(c, f);
    }
    fprintf(f, "\n");
    fclose(f);
}
int extract(char *dest, char *tarball)
{
    char s[512] = {0};
    char contents[512] = {0};
    FILE *f = fopen(tarball, "r");
    FILE *n;
    char command[256] = "mkdir ";
    strcat(command, dest);
    system(command);
    char name[512] = {0};
    int size = 0;
    while (fgets(s, 511, f))
    {
        if (strstr(s, "Name:"))
            {
                s[0] = '\0';
                s[1] = '\0';
                s[2] = '\0';
                s[3] = '\0';
                s[4] = '\0';
                strcpy(s, name);
                mknod(dest, 0777, 0);
                n = fopen(dest, "w");
            }
        else if (strstr(s, "Size:"))
        {
            s[0] = '\0';
            s[1] = '\0';
            s[2] = '\0';
            s[3] = '\0';
            s[4] = '\0';
            size = atoi(s);
        }
        fgets(contents, size, f);
        fputs(contents, n);
    }
}
int main(int argc, char **argv)
{
    if (argc < 3)
    {
        puts("Not enough arguments\n");
    }
    else if (strstr(argv[2], "c"))
    {
        for (int i = 2; i <= argc; i++)
        {
            createtar(argv[2], argv[i]);
        }
        puts("Done\n");
    }
    else if (strstr(argv[1], "x"))
    {
        puts("Not done yet\n\007");
    }
    return (0);
}