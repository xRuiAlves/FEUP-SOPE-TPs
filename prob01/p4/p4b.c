#include <stdio.h>
#include <stdlib.h>

int main(int argc , char* argv[]){
	// Check if right number of arguments
	if (argc < 2){
		printf("Insuficient number of arguments.\n");
		return 1;
	}

	// Check how many times to print the name
	unsigned int repetitions = (unsigned int) atoi(argv[argc-1]);
	
	unsigned int i , j;
	for (i=0 ; i<repetitions ; i++){
		printf("Hello");
		for (j=1 ; j<(argc-1) ; j++) printf(" %s" , argv[j]);
		printf("!\n");
	}

	return 0;
}
