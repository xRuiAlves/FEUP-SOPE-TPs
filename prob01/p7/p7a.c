#include <stdio.h>
#include <stdlib.h>

static void exit_handler_1() {
	printf("Executing exit handler 1\n");
}

static void exit_handler_2() {
	printf("Executing exit handler 2\n");
}

int main(){
	atexit(exit_handler_1);
	atexit(exit_handler_2);

	printf("Main done!\n");

	return 0;
}
