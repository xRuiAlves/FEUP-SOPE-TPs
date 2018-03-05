#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    if (argc != 2  &&  argc != 3) {
        printf("usage: %s <dirname>\n  or\nusage: %s <dirname> <filenam>\n",argv[0],argv[0]);
        return 1;
    }

    // Fork call
    pid_t pid = fork();
    
    // Check for error in pid call
    if (pid < 0) {
        perror("Error");
        exit(1);
    }
   
    // Parent Process
    else if (pid > 0) {
        printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]);
        
        // Wait for child process to return
        int child_return;
        wait(&child_return);
        
        if (child_return != 0){
            printf("Failed.\n");
        }
        else{
            printf("Success.\n");
        }   
    }
    
    // Child Process
    else {
        if (argc == 3) { // User entered a file - the "ls" command output should be written there
            int fd = open(argv[2] , O_WRONLY | O_CREAT | O_EXCL , 00644);
            
            if (fd == -1) {
                printf("Error creating the file %s (it may already exist)\n" , argv[2]);
                exit(2);
            }
            
            // Redirected STDOUT to the opened file and check for error
            if (dup2(fd , STDOUT_FILENO) == -1)  {
                printf("Failed to redirect output to the given file.\n");
                exit(3);
            }
        }
        
        write(STDOUT_FILENO , "hello" , 5);
        
        execlp("ls" , "ls" , "-laR" , argv[1] , NULL);    // ls -laR
        printf("Command not executed !\n");
        exit(1);
    }
    
    return 0;
}
