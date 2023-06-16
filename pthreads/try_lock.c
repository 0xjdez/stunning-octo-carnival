#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 10
// four mutexes for four shared variables
#define NUM_MUTEXES 4
#define NUM_STOVES 4
// mutex to lock stove_fuel
pthread_mutex_t fuel_mutexes[NUM_MUTEXES];
// stove_fuel global variable accessible by all threads
int stove_fuel[NUM_STOVES] = {100,100,100,100};
void *routine(void *arg) {
    // try to unlock any of the mutexes
    for (int i = 0; i < NUM_MUTEXES; i++) {
        if (pthread_mutex_trylock(&fuel_mutexes[i]) == 0) { // if the get lock operation is successful
            int fuel_needed = (rand() % 30);
            if (stove_fuel[i] - fuel_needed < 0) {
                printf("Not enough stove_fuel, going home\n");
            }else {
                stove_fuel[i] -= fuel_needed;
                // usleep(500000);
                printf("Fuel left in stove (%d): %d\n", i,stove_fuel[i]);
            }
            pthread_mutex_unlock(&fuel_mutexes[i]);
            break;  // Work done; break from operation. Don't unlock another mutex
        } else {
            if (i == 3) {   // if last stove variable, wait...
                printf("Trying to get stove\n");
                usleep(300000); // wait before trying again..
                i = 0;  // go back to beginning of operation
            }
        }
    }
}


int main(void) {
    srand(time(NULL));
    pthread_t th[NUM_THREADS];
    // initialized all the mutexes
    for (int i = 0; i < NUM_MUTEXES; i++) {
        pthread_mutex_init(&fuel_mutexes[i], NULL);
    }

    // create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
            perror("Unable to create thread");
        }
    }

    // wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Thread unable to join");
        }
    }
    // destroy all the mutexes
    for (int i = 0; i < NUM_MUTEXES; i++) {
        pthread_mutex_destroy(&fuel_mutexes[i]);
    }
}