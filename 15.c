#include<stdio.h>

extern char **environ;

void main(){
	for(size_t i=0; environ[i]!=NULL; i++)
	{
		printf("%s\n",environ[i]);
	}
}
