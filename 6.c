#include<stdio.h>
#include<unistd.h>

int main()
{
	char buffer[32];
	read(0,buffer,sizeof(buffer));
	write(1,buffer,sizeof(buffer));
	return 0;
}
