#include "max.h"
int main(int argc, char **argv)
{
    sleep(atoi(argv[1]));
    for (;;)
        {
            putchar('\007');
        }
}