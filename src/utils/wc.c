#include <stdio.h>
#include <string.h>

int 
main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        {
            printf("Error opening file\n");
            return 1;
        }
    if (argc < 3)
    {
        int c;
        int k = 1;
        while ((c = fgetc(f))!= EOF)
            {
                if (c == ' ')
                    k++;
            }
        printf("%d words\n", k);
        return 0;
    }
    if (f != NULL)
        {
            int w = 0;
            int l = 0;
            int c;
            while ((c = fgetc(f))!= EOF)
                {
                    if (c == '\n' && strstr(argv[2], "l") || c == '\n' && strstr(argv[2], "a"))
                        l++;
                    if (c == ' ' && argv[2][0] == '\0' || c == ' ' && strstr(argv[2], "a"))
                        w++;
                }
            if (strstr(argv[2], "l"))
                printf("%d lines\n", l);
            else if (strstr(argv[2], "w") || argv[2][0] == '\0')
                printf("%d words\n", w);
            else if (strstr(argv[2], "a"))
                printf("%d lines and %d words\n", l, w);
        }
    fclose(f);
    return 0;
}