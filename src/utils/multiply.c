
#include <stdio.h>
#include <string.h>



int
main(int argc, char **argv)
{
    if (fopen(argv[1], "r") == NULL && argc > 1)
        {
            FILE *bin = fopen(argv[1], "w");
            fclose(bin);
        }
    FILE *f;
    if (argc > 1)
        f = fopen(argv[1], "w");
    else if (argc < 2)
        {
            f = fopen("/dev/null", "w");
        }
    for (int i = 0; i < 1024; i++)
    {
        for (int j = 0; j < 1024; j++)
        {
            fprintf(f, "\0");
        }
    }
    for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
                {
                    if (argc > 1)
                        fprintf(f, "%d\t", i * j);
                    else
                        fprintf(stdout, "%d\t", i * j);
                }
            fprintf(f, "\n");
        }
    fclose(f);
    return (0);
}