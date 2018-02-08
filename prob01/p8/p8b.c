#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define INTERVAL_EXTREME_INDEX 1
#define TERMINATION_VALUE_INDEX 2

int main(int argc , char* argv[]){
	clock_t ti = clock();

	if (argc != 3){
		printf("usage: p8a n1 n2\n\tn1  Interval superior extreme\n\tn2  Final number termination\n");
		return 1;
	}

	// Parse the user input
	int top_extreme = atoi(argv[INTERVAL_EXTREME_INDEX]);
	int termination_val = atoi(argv[TERMINATION_VALUE_INDEX]);

	if (termination_val >= top_extreme){
		printf("Termination Value can't be greater nor equal to the Superior Interval Extreme!\n");
		return 2;
	}

	srand(time(0));

	int random_number;

	do{
		random_number = rand()%top_extreme;
		printf("%d\t" , random_number);
	} while(random_number != termination_val);

	clock_t tf = clock();

	double run_time = (double)(tf - ti) / CLOCKS_PER_SEC;
	
	printf("\nTotal program time: %lf\n" , run_time );
	

	return 0;
}
