#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>


#define NUM_THREADS 4

static pthread_mutex_t fuel_mutex;
static sem_t fuel_sem;
static int fuel = 50;

void *routine(void *arg) {
    pthread_mutex_lock(&fuel_mutex);
    fuel += 50;
    printf("Incremented fuel to: %d\n", fuel);
    pthread_mutex_unlock(&fuel_mutex);
}


int main(void) {
    pthread_t th[NUM_THREADS];
    pthread_mutex_init(&fuel_mutex, NULL);
    sem_init(&fuel_sem, 0, 1);
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
            perror("Unable to create thread");
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Thread unable to join");
        }
    }
    pthread_mutex_destroy(&fuel_mutex);
    sem_destroy(&fuel_sem);

    printf("Fuel: %d\n", fuel);
    return EXIT_SUCCESS;
}