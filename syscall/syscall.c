#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
// #include <errno.h>

int main(void){
    int fd;
    if ((fd = open("foo", O_CREAT|O_RDWR|O_APPEND, 0644)) < 0) {
        perror("foo");
        exit(1);
    }

    int i;
    for (i = 0; i < 20; i++)
        write(fd, "Hello, World!\n", 14);
    close(fd);
}