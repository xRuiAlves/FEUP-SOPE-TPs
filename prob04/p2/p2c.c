#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signo) {
    printf("\nEntering SIGINT handler ...\n");
    sleep(5);
    printf("\nExiting SIGINT handler ...\n");
}


void sigterm_handler(int signo) {
    printf("\nEntering SIGTERM handler ...\n");
    printf("\nExiting SIGTERM handler ...\n");
}


int main(void) {

    // SIGINT Handler
    struct sigaction int_action;
    int_action.sa_handler = sigint_handler;
    sigemptyset(&int_action.sa_mask);
    int_action.sa_flags = 0;
    
    // SIGTERM Handler
    struct sigaction term_action;
    term_action.sa_handler = sigterm_handler;
    sigemptyset(&term_action.sa_mask);
    term_action.sa_flags = 0;
    
    if (sigaction(SIGINT,&int_action,NULL) < 0) {
        fprintf(stderr,"Unable to install SIGINT handler\n");
        exit(1);
    }
    
    if (sigaction(SIGTERM,&term_action,NULL) < 0) {
        fprintf(stderr,"Unable to install SIGTERM handler\n");
        exit(1);
    }
    
    printf("Try me with CTRL-C ...\n");
    
    pause();
    
    exit(0);
    
} 
