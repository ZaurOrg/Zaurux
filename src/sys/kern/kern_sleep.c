#include "syscall.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void sleep(unsigned sec)
{
    time_t t = time(NULL);
    time_t t2 = time(NULL);
    for (;;)
    {
        t2 = time(NULL);
        if (t2 - t > 0)
          {
            if (t2 - t >= sec)
              {
                break;
                return 0;
            	}
              else 
                {
                  // Do nothing ( ͡° ͜ʖ ͡°) 
                }
            }
        else if (time(NULL) < t)
            {
              // Do nothing \_(ツ)_/
            }
			return; 
    }
}