
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <syscall.h>

#define NUM_THREADS 2

void *routine(void *arg) {
    pthread_t td = pthread_self();
    printf("Thread: %lu\n", td);
    printf("%d\n", (pid_t)syscall(SYS_gettid));
}

int main(void) {
    // create an array of two threads
    pthread_t tid[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&tid[i], NULL, &routine, NULL) != 0){
            perror("Failed to create thread");
        }

        // printf("Thread: %lu\n", tid[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(tid[i], NULL) != 0) {
            perror("Thread failed to join");
        }
    }
}