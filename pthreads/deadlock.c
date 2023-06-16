#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 8

pthread_mutex_t fuel_mutex;
int fuel = 50;
pthread_mutex_t water_mutex;
int water = 10;

void *routine(void *arg){
    if (rand()%2 == 0) {
        pthread_mutex_lock(&fuel_mutex);
        // sleep for 1 second for another thread to acquire other lock
        // to cause a deadlock
        sleep(1);
        pthread_mutex_lock(&water_mutex);
    }else {
        pthread_mutex_lock(&water_mutex);
        sleep(1);
        pthread_mutex_lock(&fuel_mutex);
    }
    fuel += 50;
    water = fuel;
    printf("Incremented fuel to: %d and set water to %d\n", fuel, water);
    pthread_mutex_unlock(&fuel_mutex);
    pthread_mutex_unlock(&water_mutex);
}

int main(void) {
    pthread_t th[NUM_THREADS];
    pthread_mutex_init(&fuel_mutex, NULL);
    pthread_mutex_init(&water_mutex, NULL);
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

    printf("Value of fuel: %d\n", fuel);
    pthread_mutex_destroy(&fuel_mutex);
    pthread_mutex_destroy(&water_mutex);
    return EXIT_SUCCESS;
}