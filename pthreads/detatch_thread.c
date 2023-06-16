
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 2

void *routine(void *arg){
    sleep(1);
    printf("Finished execution\n");
}

int main(void) {
    pthread_t tid[NUM_THREADS];
    // // create threads in non detached manner and detach them: not ideal!
    // // if thread operation is fast enough, it will finish running before
    // // being detached, making its resources to not be cleaned up.
    // int i;
    // for (i = 0; i < NUM_THREADS; i++) {
    //     if (pthread_create(&tid[i], NULL, &routine, NULL) != 0) {
    //         perror("Unable to create thread");
    //     }
    //     pthread_detach(tid[i]);
    // }

    pthread_attr_t detach_thread_attr;
    pthread_attr_init(&detach_thread_attr);
    pthread_attr_setdetachstate(&detach_thread_attr, PTHREAD_CREATE_DETACHED);
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&tid[i], &detach_thread_attr, &routine, NULL) != 0) {
            perror("Unable to create thread");
        }
        pthread_detach(tid[i]);
    }

    // for (i = 0; i < NUM_THREADS; i++) {
    //     // detached threads are not joinable
    //     if (pthread_join(tid[i], NULL) != 0) {
    //         perror("Thread unable to join");
    //     }
    // }

    pthread_attr_destroy(&detach_thread_attr);
    pthread_exit(EXIT_SUCCESS);
}