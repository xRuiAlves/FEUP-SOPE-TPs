#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    if (argc != 2) {
        printf("usage: %s <dirname>\n",argv[0]);
        return 1;
    }

    // Fork call
    pid_t pid = fork();
    
    // Check for error in pid call
    if (pid < 0) {
        perror("Error");
        return 1;
    }
   
    // Parent Process
    else if (pid > 0) {
        int child_return;
        
        wait(&child_return);
        
        printf("\n\nChild Process return value: %d\n" , child_return);
        
        if (WIFEXITED(child_return)) {
            printf("Process terminated normally.\n");
        }
        else if (WIFSIGNALED(child_return)) {
            printf("Process was signaled.\n");
        }
    }
    
    // Child Process
    else {
        execlp("ls" , "ls" , "-laR" , argv[1] , NULL);    // ls -laR
        printf("Command not executed !\n");
        exit(1);
    }
    
    return 0;
}
