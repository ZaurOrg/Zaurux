#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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