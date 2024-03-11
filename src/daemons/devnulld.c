#include <stdio.h>


int main()
{
    FILE *f = fopen("null", "rw");
    for (;;)
    {
        fputc('\0', f);
    }
    return 0;
}