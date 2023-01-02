#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]){
    printf("hello, world (pid: %d)\n", getpid());

    int rc = fork();
    if (rc < 0) {   // failed fork
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0){ // fork() was successful
        printf("Hello, I am child (pid: %d)\n", getpid());
    }
    else {
        printf("Hello, I am parent of %d (pid: %d)\n", rc, getpid());
    }
    return 0;
}