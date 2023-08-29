#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include<string.h>
#include <sys/stat.h>

int main() {
    int fd;
    fd = open("file17.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    struct flock lock = {F_WRLCK, SEEK_SET, 0, 0, 0};
    lock.l_type = F_WRLCK;
    lock.l_pid = getpid();
    printf("Press enter to get lock");
    getchar();
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        exit(1);
    }
    int tkt;
    char buffer[20];
    printf("Enter the ticket number: ");
    scanf("%d", &tkt);
    snprintf(buffer, sizeof(buffer), "%d\n", tkt);
    ssize_t br;
    br = write(fd, buffer, strlen(buffer));
    if(br == -1){
        perror("Error in writing to the file");
        exit(1);
    }
    printf("Ticket Reserved.\n Ticket number: %d\n", tkt);
    printf("Press enter to release lock");
    getchar();
    getchar();
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl");
        exit(1);
    }
    close(fd);
    return 0;
}
