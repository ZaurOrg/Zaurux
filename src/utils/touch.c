#include <stdio.h>


int main(int argc, char **argv)
{
    FILE *f;
    for (int i = 2; i < argc; i++) 
    {
        if (fopen(argv[i-1], "r") != NULL)
            {
                printf("File %s already exists\n", argv[i-1]);
                return -1;
            }
        f = fopen(argv[i-1], "w");
        fclose(f);
    }
}