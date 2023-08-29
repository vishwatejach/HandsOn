#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int fdr = open("file8.txt",O_RDONLY);
	if(fdr == -1)
	{
		printf("UNABLE TO OPEN THE FILE \n");
		return 0;
	}
	
	while(1)
	{
		char ch;
		int r = read(fdr,&ch,1);
		printf("%c",ch);
		if(r == 0)
			break;
		if(ch == '\n')
			printf("\n");
	}
	
	int fd_close = close(fdr);
	return 0;
}

