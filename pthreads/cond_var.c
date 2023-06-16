#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 2

pthread_mutex_t fuel_mutex;
pthread_cond_t fuel_cond;
int fuel = 0;

void *car_fill(void *arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&fuel_mutex);
        fuel += 15;
        printf("Filled fuel: %d\n", fuel);
        pthread_mutex_unlock(&fuel_mutex);
        pthread_cond_signal(&fuel_cond);
        sleep(1);
    }
    
}

void *car(void *arg) {
    pthread_mutex_lock(&fuel_mutex);
    while (fuel < 40) {
        printf("No fuel, waiting...\n");
        pthread_cond_wait(&fuel_cond, &fuel_mutex);
        // equivqlent to:
        // pthread_mutex_unlock(&fuel_mutex)
        // wait for signal on fuel_cond
        // pthread_mutex_lock(&fuel_mutex)
    }
    fuel -= 40;
    printf("Got fuel. Now left: %d\n", fuel);
    pthread_mutex_unlock(&fuel_mutex);
}

int main(void) {
    pthread_t tid[NUM_THREADS];
    pthread_mutex_init(&fuel_mutex, NULL);
    pthread_cond_init(&fuel_cond, NULL);
    for (int i = 0; i < NUM_THREADS; i++) {
        if (i == 1) {
            if (pthread_create(&tid[i], NULL, &car_fill, NULL) != 0) {
                fprintf(stderr, "Unable to create thread\n");
            }
        } else {
            if (pthread_create(&tid[i], NULL, &car, NULL) != 0) {
                fprintf(stderr, "Unable to create thread\n");
            }
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(tid[i], NULL) != 0) {
            fprintf(stderr, "Thread unable to join\n");
        }
    }
    pthread_mutex_destroy(&fuel_mutex);
    pthread_cond_destroy(&fuel_cond);
    return EXIT_SUCCESS;
}