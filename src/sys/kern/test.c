#include "syscall.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    sleep(1);
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("Hello, world!\nI am a child process!\n");
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
    }
    else if (pid == -1)
    {
        printf("Oops, i wasn't forked properly.\n");
        panic("fork failed");
    }
    else
    {
        printf("I am a parent process, i'm waiting for my child to go back\n");
        wait(NULL);
    }
    return (0);
}