#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_NAME_LEN 100

typedef struct Student {
	char name[MAX_NAME_LEN];
	int grade;
} Student;

int main(int argc , char** argv){
	// Verify correct usage
	if (argc != 2) {
		printf("usage: %s <file_name>\n" , argv[0]);
		return 1;	
	}

	// Open the file
	int file_fd = open(argv[1] , O_RDONLY);
	if (file_fd == -1) {
		printf("Failed to open file for reading.\n");
		return 2;
	}

	// Read student names and grades and print them to the screen
	Student s;
	
	while( read(file_fd , &s , sizeof(Student)) > 0){
	    printf("Name: %s          Grade: %d\n" , s.name , s.grade);
	}

	// Close the file
	close(file_fd);


	return 0;
}
