// for some reasons, this is defined in order for
// pthread_barrier_t to work.
#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <threads.h>

#define NUM_THREADS 2

pthread_barrier_t barrier;

void *routine(void *arg) {
    printf("Waiting on barrier....\n");
    pthread_barrier_wait(&barrier);
    printf("Done waiting....can proceed now");
}

int main(void) {
    pthread_t tid[NUM_THREADS];
    pthread_barrier_init(&barrier, NULL, 3);
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&tid[i], NULL, &routine, NULL) != 0) {
            perror("Unable to create thread");
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(tid[i], NULL) != 0) {
            perror("thread unable to join");
        }
    }

    pthread_barrier_destroy(&barrier);
}