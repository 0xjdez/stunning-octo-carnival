/**
 * Recursive mutexes can find application in recursive functions
 * that use a shared memory.
*/


// this macro is required for some reason to make recursive
// mutexes work....sometimes.
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4

static pthread_mutex_t fuel_mutex;
static int fuel = 0;

void *routine(void *arg) {
    pthread_mutex_lock(&fuel_mutex);
    fuel += 50;
    printf("Incremented to fuel to: %d\n", fuel);
    pthread_mutex_unlock(&fuel_mutex);
}

int main(void) {
    pthread_t th[NUM_THREADS];
    pthread_mutexattr_t recursive_attr;
    pthread_mutexattr_init(&recursive_attr);
    // setting a mutex as recursive makes locking it twice to
    // not lead to deadlock.
    pthread_mutexattr_settype(&recursive_attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&fuel_mutex, NULL);
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&th[i], NULL, routine, NULL) != 0) {
            perror("Unable to create thread");
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Thread unable to join");
        }
    }

    printf("Fuel: %d\n", fuel);
    pthread_mutexattr_destroy(&recursive_attr);
    pthread_mutex_destroy(&fuel_mutex);
    return EXIT_SUCCESS;
}