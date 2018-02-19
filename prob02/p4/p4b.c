#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_NAME_LEN 100
#define MAX_NUM_STUDENTS 10
#define MAX_NUM_LEN 15

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
	int file_fd = open(argv[1] , O_WRONLY | O_TRUNC);
	if (file_fd == -1) {
		printf("Failed to open file for writting.\n");
		return 2;
	}

	// Read student names and grades
	Student students[MAX_NUM_STUDENTS];

	printf("Enter %d student names and their respective grades.\n" , MAX_NUM_STUDENTS);
		
	int i;
	Student s;
	for (i=0 ; i<MAX_NUM_STUDENTS ; i++) {
		// Read the name
		printf("\nName: ");
		fgets(s.name , MAX_NAME_LEN , stdin);

		// Read the grade
		printf("Grade: ");
		scanf("%d" , &s.grade);
		getchar();	// Ignore \n from input stream

		// Store the student in the array
		students[i] = s;
	}

	// Write them to a file
	for (i=0 ; i<MAX_NUM_STUDENTS ; i++) {
		write(file_fd , &students[i] , sizeof(Student));
	}

	// Close the file
	close(file_fd);


	return 0;
}
