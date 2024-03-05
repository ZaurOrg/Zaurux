/*
*   Copyright 2024 AnatoliyL
*   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer
*   2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
*   3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*   4. All products derived from this software must retain permittion to redistribute, use in source and binary forms, with or without modification.
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <stdio.h>
int k = 0;
void beer99(void)
{
	for (int beer = 99; beer > 1; --beer)
	{
		printf("%d bottles of beer on the wall, %d bottles of beer\n", beer, beer);
		printf("Take one down, pass it around, %d bottles of beer on the wall!\n", --beer);
	}
	puts("1 bottle of beer on the wall, 1 bottle of beer\nTake on down, pass it around, no more bottles of beer on the wall!\n");
	puts("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some, 99 bottles of beer on the wall\n");
}
int hq9p(char *source)
{
  for (int i = 0; i < sizeof(source); i++)
  {
	switch(source[i])
	  	{
		  	case 'H':
				printf("Hello, world!\n");
				break;
		  	case 'Q':
				printf("%s\n", source);
				break;
		  	case '9':
				beer99();
				break;
		  	case '+':
		  		++k;
			case 'P':
		  		++k;
		  	break;
	  	}
  }
  return (0);
}
void hq9open(char *name)
{
  FILE *f = fopen(name, "r");
  char source[1024];
  fgets(source, 1023, f);
  hq9p(source);
}
int main(int argc, char **argv)
{
  hq9open(argv[1]);
}