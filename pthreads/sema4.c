#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

// number of threads
#define NUM_THREAD 4

// semaphore for synchronization
sem_t semafore;

void *routine(void *arg){
    // sem_wait is like mutex_lock
    sem_wait(&semafore);
    sleep(1);
    printf("Hello from thread number: %d\n", *(int*)arg);
    // sem_post is like mutex_unlock
    sem_post(&semafore);
    free(arg);
}

int main(void) {
    pthread_t th[NUM_THREAD];
    int i;
    sem_init(&semafore, 0, 1);
    for (i = 0; i < NUM_THREAD; i++) {
        int *a = (int*)malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Unable to create thread");
        }
    }

    for (i = 0; i < NUM_THREAD; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Thread unable to join");
        }
    }

    // free resource
    sem_destroy(&semafore);
}