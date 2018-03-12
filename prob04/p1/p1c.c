#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo) {
    printf("In SIGINT handler ...\n");
    sleep(15);
    printf("Exiting Sig Handler\n");
}

int main(void) {
    
    struct sigaction int_action;
    
    int_action.sa_handler = sigint_handler;
    
    sigemptyset( &(int_action.sa_mask) );
    sigaddset( &(int_action.sa_mask) , SIGTERM );
    
    sigaction(SIGINT , &int_action , NULL);
    
    
    printf("Sleeping for 30 seconds ...\n");
    int sleep_return = sleep(30);
    
    while (sleep_return != 0) {
        sleep_return = sleep(sleep_return);
    }
  
    
    printf("Waking up ...\n");
    
    exit(0);
} 
