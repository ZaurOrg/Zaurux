
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

int main(int argc, char **argv) 
{
    char cmd[32];
    char in[2048];
    char buf[32767];
    for (;;)
    {
        if (strcmp(cmd, "i") != 0)
        {
            printf(":");
            fgets(cmd, 31, stdin);
            cmd[strlen(cmd) - 1] = '\0';
        }
        if (strstr(cmd, "i") == 0)
        {
            FILE *f = fopen(argv[1], "w");
            getchar();
            while (strcmp(in, "^C") != 0)
            {
                fgets(in, 2047, stdin);
                strncat(buf, in, 2047);
                if (strstr(in, "quit^C\n") == 0)
                {
                    printf(":");
                    getchar();
                    fgets(cmd, 31, stdin);
                    cmd[strlen(cmd) - 1] = '\0';
                    if (strstr(cmd, "wq") == 0)
                    {
                        FILE *f;
                        if (argc < 2)
                        {
                            printf("You haven't specified a file to write to!\n");
                            break;
                        }
                        else if (fopen(argv[1], "r") == NULL)
                        {
                            f = fopen(argv[1], "w");
                            fputs(buf, f);
                        }   
                    }
                }
            }
        }
    }
}