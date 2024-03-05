#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/*
*   Copyright 2024 AnatoliyL
*   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer
*   2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
*   3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*   4. All products derived from this software must retain permittion to redistribute, use in source and binary forms, with or without modification.
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#define BUFFER_LEN 1024

int main(){
    char user_input[BUFFER_LEN];  //get command line
    char* argv[120]; //user command
    int argc ; //argument count
    char* path= "/bin/"; 
    char file_path[50];//full file path

    while(1)
    {
        printf("$ ");  // Greeting shell during startup               
        
        if(!fgets(user_input,BUFFER_LEN, stdin)){
            break;  //break if the command length exceed the defined BUFFER_LEN
        }
        
        size_t length = strlen(user_input);

        if(length == 0){
            break;
        }

        if (user_input[length - 1] == '\n'){
            user_input[length - 1] = '\0'; // replace last char by '\0' if it is new line char
        }
        
        //split command using spaces
        char *token;                  
        token = strtok(user_input," ");
        int argc=0;
        if(token == NULL){
            continue;
        }
        while(token!=NULL){
            argv[argc]=token;      
            token = strtok(NULL," ");
            argc++;
        }
        
        argv[argc]=NULL; 
        
        strcpy(file_path, path);  //Assign path to file_path 
        strcat(file_path, argv[0]); //conctanate command and file path           

        if (access(file_path,F_OK)==0){  //check the command is available in /bin
        
            pid_t pid, wpid;
            int status;
            
            pid = fork();
            if (pid == 0) { //child process 
                if (execvp(file_path,argv) == -1) {
                  perror("Child proccess end"); 
                }
                exit(EXIT_FAILURE);
            } 
            else if (pid > 0) { // parent process
                wpid = waitpid(pid, &status, WUNTRACED); 
                while (!WIFEXITED(status) && !WIFSIGNALED(status)){
                    wpid = waitpid(pid, &status, WUNTRACED); 
                }
            } 
            else {
                perror("Fork Failed"); //process id can not be null 
            }
        }
        else {
            printf("Command not found\n"); //Command is not available in the bin
        }

    }
} 