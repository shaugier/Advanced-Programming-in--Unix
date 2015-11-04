#include"apue.h"
#include<dirent.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if(argc != 2)
	{
		printf("argc is not 2!\n");
		exit(-1);
	}
	if((dp = opendir(argv[1]))==NULL)
	{
		printf("open failed!\n");
		exit(-1);
	}
	while((dirp = readdir(dp)) != NULL)
		printf("%s   ",dirp->d_name);
	closedir(dp);
	exit(0);
}
