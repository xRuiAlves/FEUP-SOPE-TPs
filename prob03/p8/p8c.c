#include <stdio.h>
#include <sys/types.h>
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
        printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]);
    }
    
    // Child Process
    else {
        char* arguments[] = {"ls" , "-laR" , argv[1] , NULL};
        execvp("ls" , arguments);    // ls -laR
        printf("Command not executed !\n");
        exit(1);
    }
    
    return 0;
}
