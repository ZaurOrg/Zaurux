#include <stdio.h>
#include <string.h>

/*
*   Copyright 2024 AnatoliyL
*   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer
*   2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
*   3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*   4. All products derived from this software must retain permittion to redistribute, use in source and binary forms, with or without modification.
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

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