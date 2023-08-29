#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/file.h>

void main() {
  struct flock lock;
  int fd=open("file16_a.txt", O_RDONLY | O_CREAT, 0666);
  if(fd < 0) {
    perror("open");
    exit(0);
  }
  lock.l_type=F_RDLCK;
  lock.l_whence=SEEK_SET;
  lock.l_start=0;
  lock.l_len=0;
  int rfcntl=fcntl(fd, F_SETLKW, &lock);
  
  if(rfcntl < 0) {
    perror("fcntl");
    exit(1);
  }
  printf("Read lock set\n");
  read(fd, "This is a mandatory read lock.", 26);
  printf("Press enter to unlock");
  getchar();
  lock.l_type=F_UNLCK;
  rfcntl=fcntl(fd, F_SETLKW, &lock);
  if(rfcntl < 0) {
    perror("fcntl");
    exit(1);
  }
  close(fd);
}
