#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
*   Copyright 2024 AnatoliyL
*   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer
*   2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
*   3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*   4. All products derived from this software must retain permittion to redistribute, use in source and binary forms, with or without modification.
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
int main(int argc, char **argv)
{
    if (fopen("pkgmconf/version.config", "r") == NULL)
    {
        printf("pkgmconf/version.config does not exist\nPlease reinstall the package manager or create /etc/pkgmconf/version.config file\n");
        return -1;
    }
    if (argc < 2)
    {
        FILE *f = fopen("pkgmconf/version.config", "r");
        FILE *f2 = fopen("pkgmconf/info.txt", "r");
        char *version;
        fgets(version, 16, f);
        printf("pkgm version %s.\n", version);
        int c = (int)NULL;
        while ((c = fgetc(f2)) != EOF)
        {
            putchar(c);
        }
        return 0;
    }
    else if (argc == 2 && strcmp(argv[1], "install") == 0 || argc == 2 && strcmp(argv[1], "update") == 0 || argc == 2 && strcmp(argv[1], "remove") == 0)
    {
        printf("You haven't specified a package\n");
        return -1;
    }
    else if (argc == 2 && strcmp(argv[1], "install") != 0 && strcmp(argv[1], "update") != 0 && strcmp(argv[1], "remove") != 0)
    {
        printf("Usage: pkgm <install|update|remove> <package>\n");
        return -1;
    }
    else
    {
        char *package = argv[3];
        char *tmp;
        if (strcmp(argv[1], "install") == 0)
        {
            char *cmd = "wget ";
            char *pathtoconfig = "pkgmconf/";
            strcat(pathtoconfig, package);
            strcat(pathtoconfig, ".config");
            FILE *f = fopen(pathtoconfig, "r");
            if (f == NULL)
            {
                printf("Package %s is not in repo\n", package);
                return -1;
            }
            else
            {
                char *url;
                fgets(url, 1024, f);
                strcat(cmd, url);
                system(cmd);
                for (int i = 0; i < strlen(cmd); i++)
                {
                    cmd[i] = '\0';
                }
                strcat(cmd, "cd ");
                strcat(cmd, package);
                system(cmd);
                for (int i = 0; i < strlen(cmd); i++)
                {
                    cmd[i] = '\0';
                }
                system("./configure && make && make install");
                return (0);
            }
        }
        else if (strcmp(argv[1], "update") == 0)
        {
            char *cmd = "wget ";
            char *pathtoconfig = "pkgmconf/";
            strcat(pathtoconfig, package);
            strcat(pathtoconfig, ".config");
            FILE *f = fopen(pathtoconfig, "r");
            if (f == NULL)
            {
                printf("Package %s is not in repo\n", package);
                return -1;
            }
            else
            {
                char *url;
                fgets(url, 1024, f);
                strcat(cmd, url);
                system(cmd);
                for (int i = 0; i < strlen(cmd); i++)
                {
                    cmd[i] = '\0';
                }
                strcat(cmd, "tar -xJf ");
                strcat(cmd, package);
                strcat(cmd, ".txz");
                system(cmd);
                strcat(cmd, "cd ");
                strcat(cmd, package);
                system(cmd);
                for (int i = 0; i < strlen(cmd); i++)
                {
                    cmd[i] = '\0';
                }
                system("./configure && make && make install");
                return (0);
            }
        }
    }
}