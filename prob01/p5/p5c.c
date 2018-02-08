#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Hello %s!\n" , getenv("USER"));

	return 0;
}
