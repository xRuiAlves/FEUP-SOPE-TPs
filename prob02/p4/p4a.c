#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_NAME_LEN 100
#define MAX_NUM_NAMES 10
#define MAX_NUM_LEN 15

int main(int argc , char** argv){
	// Verify correct usage
	if (argc != 2) {
		printf("usage: %s <file_name>\n" , argv[0]);
		return 1;	
	}

	// Open the file
	int file_fd = open(argv[1] , O_WRONLY | O_TRUNC);
	if (file_fd == -1) {
		printf("Failed to open file for writting.\n");
		return 2;
	}

	// Read student names and grades
	char names[MAX_NUM_NAMES][MAX_NAME_LEN];
	char grades[MAX_NUM_NAMES][MAX_NUM_LEN];

	printf("Enter %d student names and their respective grades.\n" , MAX_NUM_NAMES);
		
	int i;
	for (i=0 ; i<MAX_NUM_NAMES ; i++) {
		printf("\nName: ");
		fgets(names[i] , MAX_NAME_LEN , stdin);
		printf("Grade: ");
		fgets(grades[i] , MAX_NUM_LEN , stdin);
	}

	// Write them to a file
	for (i=0 ; i<MAX_NUM_NAMES ; i++) {
		write(file_fd , names[i] , strlen(names[i])-1);
		write(file_fd , "  -  " , strlen("  -  "));
		write(file_fd , grades[i] , strlen(grades[i])-1);
		write(file_fd , "\n" , strlen("\n"));
	}

	// Close the file
	close(file_fd);


	return 0;
}
