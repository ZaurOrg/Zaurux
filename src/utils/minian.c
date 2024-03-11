#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>



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