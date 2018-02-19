#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_LEN 256

int main(int argc , char** argv){
	// Verify correct usage
	if (argc!=2 && argc!=3){
		printf("usage:\n(1)  %s <source>\n(2)  %s <source> <destiny>\n" , argv[0] , argv[0]);
		return 1;
	}
	
	// Open the "source" file
	int src_fd = open(argv[1] , O_RDONLY); 
	if (src_fd == -1) {
		printf("Failed to open the source file.\n");
		return 2;
	}

	// Open the "destiny" file
	int dst_fd;
	if (argc == 3) {
		dst_fd = open(argv[2] , O_WRONLY | O_TRUNC);
		if (dst_fd == -1){
			close(src_fd);
			printf("Failed to open the destiny file.\n");
			return 3;	
		}
		dup2(dst_fd , STDOUT_FILENO);
	}

	// Copy the file content
	char buffer[BUFFER_LEN];
	ssize_t num_chars;
	while( (num_chars = read(src_fd , buffer , BUFFER_LEN)) > 0){
		write(dst_fd , buffer , num_chars);
	}	

	// Close the files
	close(src_fd);
	close(dst_fd);
	printf("Done.\n");
	

	return 0;
}
