#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int myVar;

void usr_signals_handler(int signo) {
    if (signo == SIGUSR1) {
        printf("My var value: %d\n" , ++myVar);
    } 
    else if (signo == SIGUSR2) {
        printf("My var value: %d\n" , --myVar);
    }
    else {
        printf("Sig number: %d\n" , signo);
    }   
}

int main(void) {
     
    int fork_return = fork();
    
    srand(time(NULL));
    
    if (fork_return < 0) {
        printf("Error on forking.\n");
        exit(1);
    } 
    else if (fork_return == 0) {
        // Install handler
        struct sigaction usr_action;
        usr_action.sa_handler = usr_signals_handler;
        usr_action.sa_flags = 0;
        sigemptyset( &(usr_action.sa_mask) );
        
        sigaction(SIGUSR1 , &usr_action , NULL);
        sigaction(SIGUSR2 , &usr_action , NULL);
    
        while(1) pause();
    }
    else {
        int i;
        printf("Starting Loop ... \n\n");
        for (i=0 ; i<50 ; i++){
            if (rand()%2 == 0){
                //printf("Sending SIGUSR1 to child.\n");
                kill(fork_return , SIGUSR1);
            }
            else {
                //printf("Sending SIGUSR2 to child.\n");
                kill(fork_return , SIGUSR2);
            }
            sleep(1);
        }
        
        kill(fork_return , SIGTERM);
    }


    return 0;
}
