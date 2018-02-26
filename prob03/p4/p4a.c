#include <stdio.h>
#include <unistd.h>

int main(void){
    
    if (fork() > 0) {
        usleep(1000);
        write(STDOUT_FILENO , "world!\n" , 7);
    }
    else {
        write(STDOUT_FILENO , "Hello " , 6);
    }

    return 0;
}
