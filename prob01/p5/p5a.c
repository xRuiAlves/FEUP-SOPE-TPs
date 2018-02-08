#include <stdio.h>

int main(int argc, char **argv, char** env) {
	while ( (*env) != NULL){
		printf("%s\n", *env);
		env++;
	}

	return 0;
}
