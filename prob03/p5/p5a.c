#include <stdio.h>
#include <unistd.h>

int main(void){
    if (fork() > 0){
        write(STDOUT_FILENO , "Hello " , 6);
    }
    else{
        return 0;
    }
    
    if (fork() > 0){
        write(STDOUT_FILENO , "my " , 3);
    }
    else{
        return 0;
    }
    
    if (fork() > 0){
        write(STDOUT_FILENO , "friends!\n" , 9);
    }
    else{
        return 0;
    }

    return 0;
}
