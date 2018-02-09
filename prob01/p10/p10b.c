#include <stdio.h>
#include <string.h>
#define COMMAND_SIZE 100
#define NUM_TOKS 50

void print_tokens(char** tokens , unsigned int num_tokens){
	unsigned int i;
	
	for (i=0 ; i<num_tokens ; i++){
		printf("\n%s" , *tokens++);
	}
}

int main(){
	char command[COMMAND_SIZE];
	char* tokens[NUM_TOKS];
	const char delim[] = " ";
	char* command_token;
	unsigned int num_tokens = 0;

	printf("Enter the shell command: ");
	fgets(command, sizeof(command), stdin);
	printf("\nCommand tokens:");

	command_token = strtok(command , delim);

	while(command_token != NULL){
		tokens[num_tokens] = command_token;
		num_tokens++;
		command_token = strtok(NULL , delim);
	}

	print_tokens(tokens , num_tokens);

	return 0;
}
