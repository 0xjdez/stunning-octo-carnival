
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4

static sem_t fuel_sem;
static int fuel = 50;

void *func(void *arg) {
    sem_wait(&fuel_sem);
    fuel += 50;
    printf("Current value of fuel: %d\n", fuel);
    sem_post(&fuel_sem);
}

/**
 * semaphores can be unlocked by a thread different from
 * the one that lockled them.
*/

int main(void) {
    // initialize semaphore
    sem_init(&fuel_sem, 0, 1);
    pthread_t th[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&th[i], NULL, &func, NULL) != 0) {
            perror("Unable to create thread");
        }
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Thread unable to join");
        }
    }
    // destroy semaphore
    sem_destroy(&fuel_sem);
}