#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

int main()
{
	int fd_open;
	fd_open = open("file4.txt",O_RDWR | O_CREAT|O_EXCL,0777);
	printf("OUTPUT : %d\n",fd_open);
	if(fd_open == -1)
	{
		printf("ERROR %d\n",errno);
		perror("Program");
	}
	else 
	{
		printf("DONE!");
	}
		
}
