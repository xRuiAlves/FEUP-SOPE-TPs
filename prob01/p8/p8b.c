#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

#define INTERVAL_EXTREME_INDEX 1
#define TERMINATION_VALUE_INDEX 2

int main(int argc , char* argv[]){
	struct timeval utime_i , stime_i , utime_f , stime_f;
	struct timespec rtime_i , rtime_f;
	struct rusage res_usage;

	// Measure initial time
	getrusage(RUSAGE_SELF , &res_usage);
	clock_gettime(CLOCK_REALTIME , &rtime_i);
	stime_i = res_usage.ru_stime;
	utime_i = res_usage.ru_utime;


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


	// Measure final time
	getrusage(RUSAGE_SELF , &res_usage);
	clock_gettime(CLOCK_REALTIME , &rtime_f);
	stime_f = res_usage.ru_stime;
	utime_f = res_usage.ru_utime;
	
	printf("\n\nReal time: %f" , (rtime_f.tv_sec - rtime_i.tv_sec)*1000.0 + (rtime_f.tv_nsec - rtime_i.tv_nsec)/1000000.0);
	printf("\nSystem time: %f" , (stime_f.tv_sec - stime_i.tv_sec)*1000.0 + (stime_f.tv_usec - stime_i.tv_usec)/1000.0);
	printf("\nUser time: %f\n" , (utime_f.tv_sec - utime_i.tv_sec)*1000.0 + (utime_f.tv_usec - utime_i.tv_usec)/1000.0);

	return 0;

}
