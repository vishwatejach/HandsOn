#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
	if(argc !=2){
		printf("usage: %s <filename>\n", argv[0]);
		return 1;
	}

	const char* fname=argv[1];

	struct stat f_stat;
	if(stat(fname, &f_stat)==-1){
		perror("ERROR!");
		return 1;
	}
  	switch(f_stat.st_mode & S_IFMT) {
    		case S_IFBLK:
      		printf("block special\n");
      		break;
	    	case S_IFCHR:
		printf("character special\n");
 		break;
		case S_IFIFO:
		printf("FIFO special\n");
		break;
		case S_IFDIR:
		printf("directory\n");
		break;
		case S_IFREG:
		printf("regular\n");
		break;
		case S_IFLNK:
		printf("symbolic link\n");
		break;
		default:
		printf("not known!\n");
  }
}
