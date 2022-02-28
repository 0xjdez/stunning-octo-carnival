#include <stdio.h>
#include <unistd.h>

int main()
{

    /*the fork() system call creates a child process.*/
	for (int i = 0; i < 3; i++){
        fork();
    }
    printf("Hello, World!\n");
}
