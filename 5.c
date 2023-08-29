#include<stdio.h>
#include<fcntl.h>
#include<stdbool.h>

void main(){
	int count = 0;
	FILE* fd;
	while(1)
	{
		if(count<5)
		{
			char buf[32];
			snprintf(buf,sizeof(char)*32,"file%i.txt",count);
			fd = fopen(buf,"wb");
			fclose(fd);
			count++;
		}
	}

}
