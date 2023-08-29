#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

struct emp{
  int emp_id;
  char emp_name[20];
  int emp_sal;
};

void main() {
  struct flock lock;
  int fd=open("file18.txt", O_CREAT | O_RDWR, 0777);
  struct emp e1, e2, e3;
  e1.emp_id=1;
  e2.emp_id=2;
  e3.emp_id=3;
  strcpy(e1.emp_name, "VIKRAM");
  strcpy(e2.emp_name, "KAITHI");
  strcpy(e3.emp_name, "LEO");
  e1.emp_sal=2000000;
  e2.emp_sal=3000000;
  e3.emp_sal=2999000;
  write(fd, &e1, sizeof(struct emp));
  lock.l_type=F_WRLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 8;
  lock.l_len = 8;
  lock.l_pid = getpid();
  fcntl(fd,F_SETLKW , &lock);
  printf("Entered critical section...\n");
  printf("Press enter to unlock...\n");
  getchar();
  printf("Write lock unset...\n");
  lock.l_type=F_RDLCK;
  lock.l_start=0;
  lock.l_len=8;
  fcntl(fd, F_SETLKW, &lock);
  printf("Read lock set...\n");
  lock.l_type=F_UNLCK;
  lock.l_start=8;
  lock.l_len=8;
  fcntl(fd, F_SETLKW, &lock);
  printf("Press enter to exit...\n");
  getchar();
  printf("Read lock unset...\n");
  close(fd);
}
