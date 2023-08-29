#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>

void main(int argc, char *argv[]) {
  struct stat f_stats;
  time_t last_access, last_mod, last_changed;
  if(stat(argv[1], &f_stats) < 0) {
    perror("stat");
    exit(0);
  }
  last_access=f_stats.st_atime;
  last_mod=f_stats.st_mtime;
  last_changed=f_stats.st_ctime;
  printf("inode: %ld\n", f_stats.st_ino);
  printf("number of hard links: %ld\n", f_stats.st_nlink);
  printf("uid: %d\n", f_stats.st_uid);
  printf("gid: %d\n", f_stats.st_gid);
  printf("size: %ld\n", f_stats.st_size);
  printf("block size: %ld\n", f_stats.st_blksize);
  printf("number of blocks: %ld\n", f_stats.st_blocks);
  printf("last accessed: %s\n", ctime(&last_access));
  printf("last modified: %s\n", ctime(&last_mod));
  printf("last changed: %s\n", ctime(&last_changed));
}
