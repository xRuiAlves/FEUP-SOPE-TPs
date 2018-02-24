// PROGRAMA p6a.c ( referido na alínea a) )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_STR_SIZE 10

int main(int argc, char *argv[])
{
    DIR *dirp;
    struct dirent *direntp;
    struct stat stat_buf;
    char str[MAX_STR_SIZE];
    
    // Check if the number of parameters are correct
    if (argc != 2) {
        fprintf(stderr, "Usage: %s dir_name\n", argv[0]);
        exit(1);
    }
    
    // Try to open the directory and check for error
    if ( (dirp = opendir(argv[1])) == NULL) {
        perror(argv[1]);
        exit(2);
    }
    
    // Print info regarding each sub-directory / file
    while ((direntp = readdir( dirp)) != NULL) {
        stat(direntp->d_name, &stat_buf);
        
        // Analize type of file
        if (S_ISREG(stat_buf.st_mode)) {
            strcpy(str , "regular");
        }
        else if (S_ISDIR(stat_buf.st_mode)) {
            strcpy(str , "directory");
        }
        else {
            strcpy(str , "other");
        }
        
        printf("%-20s -   %-10s -  %ld\n", direntp->d_name, str , direntp->d_ino);
    }
    
    closedir(dirp);
    return 0;
} 
