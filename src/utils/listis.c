
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void deleten(char *);
void deleten(char *bar)
{
  bar[strlen(bar) - 1] = '\0';
}

/*
*   Copyright 2024 AnatoliyL
*   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer
*   2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
*   3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*   4. All products derived from this software must retain permittion to redistribute, use in source and binary forms, with or without modification.
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

int main(void)
{
  puts("\t\tListis\tCopyright (C) 2024 AnatoliyL\n");
  puts("This program comes with ABSOLUTELY NO WARRANTY\nThis is free software, and you are welcome to redistribute it under GNU GPL license conditions\n");
  for (int i = 0; i < 5; i++)
    putchar('\n');
  puts("To watch existing list, press 'o', to create new, press 'n'\n");
  int v = getchar();
  if (v == 'o')
    {
      char name[512];
      fgets(name, 512, stdin);
      deleten(name);
      FILE *f = fopen(name, "r");
      if (!f)
        {
          puts("Error! The file doesn't exist!\n");
          return (1);
        }
      else
        {
          int c = 0;
	  			while ((c = getc(f)) != EOF)
	    			{
              putchar(c);
            }
	  				putchar('\n');
        }
      return (0);
    }
  puts("What do you want to add to list?");
  char ls[256][256] = {0};
  getchar();
  for (int i = 0; i < 256; i++)
    {
	    printf("> ");
	    fgets(ls[i], 255, stdin);
	    if (strcmp(ls[i], "EOF\n") == 0)
	      {
	        ls[i][0] = '\0';
	        ls[i][1] = '\0';
	        ls[i][2] = '\0';
	        break;
	      }
    }
  printf("Name your list:\t");
  char name[256] = {0};
  fgets(name, 255, stdin);
  deleten(name);
  FILE *f = fopen(name, "w");
  for (int i = 0; i < 255; i++)
    {
      fputs(ls[i], f);
    }
  fclose(f);
  return (0);
}

