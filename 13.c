#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	fd_set readfds;
	struct timeval timeout;
	FD_ZERO(&readfds);
	FD_SET(0, &readfds);
	timeout.tv_sec=10;
	timeout.tv_usec=0;
	int rselect = select(1,&readfds,NULL,NULL,&timeout);
	if(rselect<0)
	{
		perror("Select");
		exit(1);
	}
	else if(rselect == 0)
	{
		printf("Data not available\n");
		exit(1);
	}
	else
	{
		printf("Data available\n");
		exit(1);
	}
	return 0;
}
