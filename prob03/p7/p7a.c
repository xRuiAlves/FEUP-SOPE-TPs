#include <stdio.h>
#include <unistd.h>

int main(int argc , char** argv){
    if (argc != 2){
        printf("usage: %s <prog_name>\n" , argv[0]);
        return 1;
    }
    
    char prog[50];
    
    // Add .c to the program name
    sprintf(prog , "%s.c" , argv[1]);
    
    // Execute gcc
    execlp("gcc" , "gcc" , prog , "-Wall" , "-o" , argv[1] , NULL);
    
    printf("Done.\n");
    return 0;
}
