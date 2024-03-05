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

/*
*   Copyright 2024 AnatoliyL
*   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer
*   2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
*   3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*   4. All products derived from this software must retain permittion to redistribute, use in source and binary forms, with or without modification.
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

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