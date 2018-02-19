#include <stdio.h>

#define BUFFER_LEN 256

int main(int argc , char** argv){
	// Verify correct usage
	if (argc != 3){
		printf("usage: %s <source> <destiny>\n" , argv[0]);
		return 1;
	}
	
	// Open the "source" file
	FILE* source = fopen(argv[1] , "r");
	if (source == NULL) {
		printf("Source file not found.\n");
		return 2;
	}	

	// Open the "destiny" file
	FILE* destiny = fopen(argv[2] , "w");
	if (destiny == NULL) {
		fclose(source);
		return 3;
	}

	// Perform the "copying" itself
	char buffer[BUFFER_LEN];
	size_t num_chars;
	while ( (num_chars = fread(buffer , sizeof(char) , BUFFER_LEN , source)) > 0){
		fwrite(buffer , sizeof(char) , num_chars , destiny);
	}
	
	// Close the files
	fclose(source);
	fclose(destiny);

	printf("Done.\n");

	return 0;
}
