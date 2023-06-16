#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 2

const int primes[10] = { 2,3,5,7,11,13,17,19,23,29};

void *routine(void *arg) {
    int index = *(int*)arg;
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += primes[index + i];
    }
    // free(arg);
    *(int*)arg = sum;
    return (void*)arg;
}


int main(void) {
    pthread_t tid[NUM_THREADS];
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        int *a = (int*)malloc(sizeof(int));
        *a = i * 5;
        if (pthread_create(&tid[i], NULL, &routine, a) != 0) {
            perror("Unable to create thread");
        }
    }

    int sum = 0;
    for (i = 0; i < NUM_THREADS; i++) {
        int *res;
        if (pthread_join(tid[i], (void**)&res) != 0) {
            perror("Thread unable to join");
        }

        sum += *(int*)res;
        free(res);
    }

    printf("Sum of primes: %d\n", sum);
}