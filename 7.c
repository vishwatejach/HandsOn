#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc , char* argv[]) {
	
	if(argc != 3)
	{
		printf("ERROR1");
		return 0;	
	}
	int fd_r = open(argv[1],O_RDONLY);
	int fd_w = open(argv[2],O_WRONLY|O_CREAT);
	if(fd_r == -1 || fd_w == -1)
		printf("ERROR2");

	while(1)
	{
		char buff;
		int char_r = read(fd_r,&buff,sizeof(buff));
		if(char_r == 0)
			break;
		int char_w = write(fd_w,&buff,1);
	}
	int fd_r_close = close(fd_r);
	int fd_w_close = close(fd_w);
	if(fd_r_close == -1 || fd_w_close == -1)
		printf("UNABLE TO CLOSE THE FILE!");
	return 0;
}
