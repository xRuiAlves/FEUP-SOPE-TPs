#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_LEN 256

int main(int argc , char** argv){
	// Verify correct usage
	if (argc != 2){
		printf("usage: %s <file_name>\n" , argv[0]);
		return 1;
	}
	
	// Open the file
	int file_fd = open(argv[1] , O_RDONLY); 
	if (file_fd == -1) {
		printf("Failed to open the file.\n");
		return 2;
	}

	// Print the file content
	char buffer[BUFFER_LEN];
	ssize_t num_chars;
	while( (num_chars = read(file_fd , buffer , BUFFER_LEN)) > 0){
		write(STDOUT_FILENO , buffer , num_chars);
	}	

	// Close the file
	close(file_fd);

	return 0;
}
