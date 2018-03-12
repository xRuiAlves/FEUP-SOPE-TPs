#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int myVar;

void usr_signals_handler(int signo) {
    if (signo == SIGUSR1) {
        myVar++;
    } 
    else if (signo == SIGUSR2) {
        myVar--;
    }
}

int main(void) {

    // Install handler
    struct sigaction usr_action;
    usr_action.sa_handler = usr_signals_handler;
    usr_action.sa_flags = 0;
    sigemptyset( &(usr_action.sa_mask) );
    
    sigaction(SIGUSR1 , &usr_action , NULL);
    sigaction(SIGUSR2 , &usr_action , NULL);
     
     
    while(1) {
        printf("My Var value: %d\n" , myVar);
        sleep(1);
    }


    return 0;
}
