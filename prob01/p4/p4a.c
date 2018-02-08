#include <stdio.h>

int main(int argc , char* argv[]){
	// Check if right number of arguments
	if (argc < 2){
		printf("Insuficient number of arguments.\n");
		return 1;
	}

	unsigned int i;
	printf("Hello");
	for (i=1 ; i<argc ; i++) printf(" %s" , argv[i]);
	printf("!\n");

	return 0;
}
