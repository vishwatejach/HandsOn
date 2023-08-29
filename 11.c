#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int fd;
	fd = open("file11.txt",O_RDWR|O_APPEND);
	if(fd == -1)
		printf("Error opening the file\n");
	//int copy_fd = dup(fd);
	write(fd,"This is from fd\n",strlen("This is from fd\n"));
	//write(copy_fd,"This is from copy_fd\n",strlen("This is from copy_fd\n"));
	//int dup_2 = dup2(fd,1);
	//printf("file11.txt");
	int fcntl_dup = fcntl(fd,F_DUPFD);
	write(fcntl_dup,"This is from fcntl_dup\n",strlen("This is from fcntl_dup\n"));
	return 0;
}
