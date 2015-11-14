#include"apue.h"
#include<unistd.h>
#include<fcntl.h>

int others_dup2(int oldfd, int newfd);

int
main(int argc, char *argv[])
{
	int fd = open("signal",O_RDWR);
	int newdup = open("printPID", O_RDWR);
//	printf("%d\n", fd);
	int newfd = others_dup2(fd, newdup);
	printf("%d\n", newfd);
}
int
others_dup2(int oldfd, int newfd)
{
	int tempfd;
	int i = 0;
	int fdarr[newfd];
	if((tempfd  = dup(oldfd)) == -1)
		err_sys("the file desp is invalid.");
	else
		close(tempfd);

	if(newfd == oldfd)
		return oldfd;
	
//	printf("%d, %d\n", oldfd,newfd);

	if(close(newfd) == -1)
		err_sys("close newfd failed\n");
	
	for(i = 0; i < newfd+1; i++)
	{
		fdarr[i] = 0;
		tempfd = dup(oldfd);
//		printf("%d  ", tempfd);
		if(tempfd == -1)
			err_sys("dup failed");
		else{
			if(tempfd == newfd)
				break;
			else fdarr[i] = 1;
		}
	}

	for(i = 0; i < newfd+1; i++)
	{
		if(fdarr[i] == 1)
			close(i);
	}
	return tempfd;
}

