#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>



#define COMMAND_SIZE 200
#define MAX_NUM_COMMANDS 20



void get_tokens(char* tokens[MAX_NUM_COMMANDS] , char command[COMMAND_SIZE] , int* numCommands) {
	const char delim[] = " ";
	char* command_token;
	*numCommands = 0;
	
	command_token = strtok(command , delim);
	
	while(command_token != NULL){
	    tokens[(*numCommands)] = command_token;
	    (*numCommands)++;
	    command_token = strtok(NULL , delim);
	}	
}

void clearLineTerminator(char command[COMMAND_SIZE]){
    int i;
    for(i=0 ; i < COMMAND_SIZE; i++){
        if(command[i] == '\n'){
            command[i] = '\0';
            return;
        }
    }
}

void prompt(char command[COMMAND_SIZE]) {
    write(STDOUT_FILENO , "\nminish > " , 10);
    fgets(command , COMMAND_SIZE , stdin);   
    clearLineTerminator(command); 
}

void checkOutputRedirection(char* tokens[MAX_NUM_COMMANDS] , int numCommands) {
    if (numCommands < 3 || strcmp(tokens[numCommands-2] , "-o")!=0) {
        return;
    }
    
    // Open file
    int fd = open(tokens[numCommands-1] , O_WRONLY | O_CREAT | O_TRUNC , 00644);
    
    if (fd == -1) {
        write(STDOUT_FILENO , "\n\nFailed to open file. Writing to STDOUT instead.\n" , 50);
        return;
    }
    
    dup2(fd , STDOUT_FILENO);
    
    tokens[numCommands-2] = NULL;
    
    return;
}

int main(){
    
    char command[COMMAND_SIZE];
    char* tokens[MAX_NUM_COMMANDS];
    int numCommands;
    
    prompt(command);
    
    while(strcmp(command , "quit") != 0){
    
        if (fork() == 0) {
            get_tokens(tokens , command , &numCommands);
                       
            tokens[numCommands] = NULL;
            
            checkOutputRedirection(tokens , numCommands);
            
            execvp(tokens[0] , tokens);       
            
            // Exec failed 
            exit(1);                        
        }
        else {
            int returnVal;
            wait(&returnVal);
            
            if (returnVal != 0) {
                write(STDOUT_FILENO , "\n\nCommand failed. Quitting.\n" , 28);
                exit(1);
            }
        }
        
        prompt(command);
    }
    
    write(STDOUT_FILENO , "\n\nTerminated Successfully.\n" , 27);

    return 0;
}
