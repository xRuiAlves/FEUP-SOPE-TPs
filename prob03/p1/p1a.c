#include <stdio.h>
#include <unistd.h>

int global=1;

int main(void) {
    int local = 2;
    int fork_return;
    
    if( (fork_return=fork()) > 0) {
        printf("PID = %d ; PPID = %d ; Fork return = %d\n", getpid(), getppid(), fork_return);
        global++;
        local--;
    } 
    else {
        printf("PID = %d ; PPID = %d ; Fork return = %d\n", getpid(), getppid(), fork_return);
        global--;
        local++;
    }
    
    printf("PID = %d ; global = %d ; local = %d\n", getpid(), global, local);
    return 0;
} 
