#include <stdio.h>
#include <unistd.h>

int main(void){
    
    
    write(STDOUT_FILENO , "Hello " , 6);
    
    if (fork() == 0) {
        write(STDOUT_FILENO , "World!\n " , 7);
    }

    return 0;
}
