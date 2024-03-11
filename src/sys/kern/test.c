#include "../../include/syscall.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    sleep(1);
    pid_t pid = fork();
    if (pid == 0)
        printf("I am new process!\n");
    else if (pid == -1)
        panic("Fork failed!");
    if (argc > 1)
    {
        printf("I want to sleep, see you in %d seconds!\n", atoi(argv[1]));
        sleep(atoi(argv[1]));
    }
    else
    {
        srand(time(NULL));
        int random = rand()%10+1;
        printf("I want to sleep, see you in %d seconds!\n", random);
        sleep(random);
    }
    return (0);
}