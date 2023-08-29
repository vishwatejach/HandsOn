#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/file.h>

void main() {
  struct flock lock;
  int fd = open("file16_b.txt", O_WRONLY|O_CREAT);
  if (fd < 0) {
    perror("open");
    exit(1);
  }
  lock.l_type = F_WRLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 0;
  if (fcntl(fd, F_SETLKW, &lock) < 0) {
    perror("fcntl");
    exit(1);
  }
  printf("Writing to the file...\n");
  write(fd, "This is a mandatory write lock.", 26);
  printf("Press return to unlock");
  getchar();
  lock.l_type = F_UNLCK;
  if (fcntl(fd, F_SETLKW, &lock) < 0) {
    perror("fcntl");
    exit(1);
  }
  close(fd);
}
