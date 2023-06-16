#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 10

void *routine(void *arg);

// create an array of 10 primes
int primes[10] = { 2,3,5,7,11,13,17,19,23,29};

int main(void) {
    pthread_t tid[NUM_THREADS];
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        int *a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&tid[i], NULL, &routine, a) != 0) {
            perror("Unable to create thread");
        }
        // // for debugging
        // printf("Address of arg in main for thread(%lu): %p\n", tid[i], a);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(tid[i], NULL) != 0) {
            perror("Thread unable to join");
        }
    }
    return 0;
}

void *routine(void *arg) {
    int index = *(int*)arg;
    printf("%d\n", primes[index]);
    // // for debugging
    // pthread_t th = pthread_self();
    // printf("Address of arg in thread for thread(%lu): %p\n", th, arg);
    free(arg);
}