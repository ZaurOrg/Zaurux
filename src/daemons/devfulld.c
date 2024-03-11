#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int 
main()
{
    char *ascii = "$#!\"%%&'()*+,-./0123456789:;<=>?@QWERTYUIOPASDFGHJKLZXCVBNM[\\]^_'qwertyuiopasdfghjklzxcvbnm{|}~";
    FILE *f = fopen("full", "rw");
    for (;;)
    {
        srand(time(NULL));
        fputc(ascii[rand()%strlen(ascii)+0], f);
    }
    return 0;
}