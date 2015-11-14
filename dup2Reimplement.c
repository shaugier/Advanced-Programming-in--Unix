#include "apue.h"
#include <unistd.h>


void 
main(int argc, char *argv[])
{
	if(argc != 3)
		err_sys("command error");
	printf("%d\n", dup2Reimplement(argv[1], argv[2]));

	exit(0);
}
int
dup2Reimplement(int oldhandle, int newhandle)
{
	int tempfd;
	int fdarr[newhandle];
	int i = 0;
	if(oldhandle == -1)
		err_sys("fd is illegal");

	if(newhandle == -1)
		err_sys("new fd is illegal");

	if(oldhandle == newhandle)
		return newhandle;
	else{ 
		close(newhandle);
		for(i; i < newhandle + 1; i++)
		{
			tempfd = dup(oldhandle);
			fdarr[i] = tempfd;
			if(tempfd == newhandle)
				break;
		}
		int len = sizeof(fdarr)/sizeof(int) - 1;
		i = 0;
		for(i; i < len; i++)
			close(fdarr[i]);
		return fdarr[len];
	}
}
