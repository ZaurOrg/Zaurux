
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) 
{
    char cmd[32];
    char in[2048];
    char buf[32767];
    for (;;)
    {
        if (strcmp(cmd, "i") != 0)
        {
            printf(":");
            fgets(cmd, 31, stdin);
            cmd[strlen(cmd) - 1] = '\0';
        }
        if (strstr(cmd, "i") == 0)
        {
            FILE *f = fopen(argv[1], "w");
            getchar();
            while (strcmp(in, "^C") != 0)
            {
                fgets(in, 2047, stdin);
                strncat(buf, in, 2047);
                if (strstr(in, "quit^C\n") == 0)
                {
                    printf(":");
                    getchar();
                    fgets(cmd, 31, stdin);
                    cmd[strlen(cmd) - 1] = '\0';
                    if (strstr(cmd, "wq") == 0)
                    {
                        FILE *f;
                        if (argc < 2)
                        {
                            printf("You haven't specified a file to write to!\n");
                            break;
                        }
                        else if (fopen(argv[1], "r") == NULL)
                        {
                            f = fopen(argv[1], "w");
                            fputs(buf, f);
                        }   
                    }
                }
            }
        }
    }
}