#include"apue.h"

int 
main(void)
{
	printf("hello shaugier from proccess ID %ld\n", (long) getpid());
	exit(0);
}
