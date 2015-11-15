#include"apue.h"
#include<errno.h>
#include<sys/types.h>

int
main(void)
{
	int i;
	pid_t pd;
	printf("pid = %d, ppid = %d\n", getpid(),getppid());

	for(i = 0; i < 2; i++)
	{
		pd = fork();
		if(pd == 0)
		{
			printf("pid = %d, ppid = %d\n", getpid(),getppid());
			printf("the fork() returns 0, i = %d\n", i);
		}else if(pd == -1){
			perror("fork error");
			exit(-1);
		}else{
			sleep(3);
			printf("pid = %d, ppid = %d\n", getpid(),getppid());
			printf("fork() returns positive integer, i = %d\n", i);
		}
	}
	exit(0);
}
