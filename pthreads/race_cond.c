#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 4
// global variable
int mails = 0;
// mutex to lock mail variable
pthread_mutex_t mutex;  /* to avoid race condition*/

// basic function to increment mail
void *routine() {
    // int i;
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}


int main(void) {
    pthread_t td[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&td[i], NULL, &routine, NULL) != 0) {
            perror("Unable to create thread");
        }

        printf("Thread %d started\n", i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(td[i], NULL) != 0) {
            perror("Thread unable to join");
        }

        printf("Thread %d has finished executing\n", i);
    }

    // destroy mutex: free memory
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
    return 0;
}