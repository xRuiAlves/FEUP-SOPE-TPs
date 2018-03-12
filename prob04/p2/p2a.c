#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signo) {
    printf("\nEntering SIGINT handler ...\n");
    sleep(5);
    printf("\nExiting SIGINT handler ...\n");
}


int main(void) {

    struct sigaction action;
    action.sa_handler = sigint_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    
    if (sigaction(SIGINT,&action,NULL) < 0) {
        fprintf(stderr,"Unable to install SIGINT handler\n");
        exit(1);
    }
    
    printf("Try me with CTRL-C ...\n");
    
    pause();
    
    exit(0);
    
} 
