// PROGRAMA p6a.c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_LENGTH 256
#define INFILE_INDEX 1
#define OUTFILE_INDEX 2

int main(int argc , char* argv[]){
	if (argc != 3){
		printf("Invalid number of arguments.\n");
		return 1;
	}

	FILE *src, *dst;
	char buf[BUF_LENGTH];

	if ( ( src = fopen( argv[INFILE_INDEX], "r" ) ) == NULL ){
		printf("Error number: %d\n" , errno);
		exit(1);
	}

	if ( ( dst = fopen( argv[OUTFILE_INDEX], "w" ) ) == NULL ){
		printf("Error number: %d\n" , errno);
		exit(2);
	} 

	while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL ){
		fputs( buf, dst );
	}

	fclose( src );
	fclose( dst );

	exit(0); // zero é geralmente indicativo de "sucesso"
} 
