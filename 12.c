#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main() {
    int fd = open("file12.txt", O_CREAT | O_RDWR, 0666);
    int mode = fcntl(fd, F_GETFL);
    printf("%d\n", mode & O_ACCMODE);
}
