#include <stdio.h>
#include <string.h>

int main(int argc, char **argv, char** env) {
	while ( (*env) != NULL){
		if (strncmp (*env ,"USER=",5) == 0){
			printf("Hello ");
			unsigned int i;
			for (i=5 ; ; i++){
				printf("%c",(*env)[i]);
				if ((*env)[i] == '\0')
					break;
			}
			printf("!\n");
			break;
		}
		env++;
	}

	return 0;
}
