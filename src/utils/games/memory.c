#include "../max.h"
const char *words[] = {"chocolate\0", "apple\0", "theater\0", "computer\0", "orange\0", "banana\0", "mouse\0"};

int 
main(int argc, char **argv)
{
    system("clear");
    char buf[1024];
    srand(time(NULL));
    for (;;)
    {
        system("clear");
        int i = rand()%7+0;
        printf("%s\n", words[i]);
        sleep(rand()%10+5);
        system("clear");
        printf("What word just dissapeared?\n");
        fgets(buf, 1023, stdin);
        buf[strlen(buf)-1] = '\0';
        if (strcmp(buf, words[i]) == 0)
            {
                printf("Yes! It was %s\nTo continue, press Enter, to end the game, press CTRL+C\n", words[i]);
                getchar();
            }
        else
            {
                printf("No! It was %s\nTo continue, press Enter, to end the game, press CTRL+C\n", words[i]);
                getchar();
            }
    }
}
