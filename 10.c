#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd;
	fd = open("file10.txt",O_RDWR|O_CREAT);
	if(fd == -1)
	{
		printf("ERROR\n");
	}
	int wr;
	write(fd,"1234567890",strlen("1234567890"));
	int seeek = lseek(fd,10,SEEK_CUR);
	write(fd,"9876543210",strlen("9876543210"));

	printf("\nReturn value of lseek : %d\n",seeek);
	system("od -c file10.txt");
	return 0;
}
