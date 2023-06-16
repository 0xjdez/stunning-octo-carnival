
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>


#define NUM_THREADS 4
sem_t sem;

void *func(void *arg) {
    int index = *(int*)arg;
    int my_sem_value;
    sem_wait(&sem);
    sleep(index+1);
    sem_getvalue(&sem, &my_sem_value);
    printf("Thread (%d): Current semaphore value after wait --> %d\n", index, my_sem_value);
    sem_post(&sem);
    sem_getvalue(&sem, &my_sem_value);
    printf("Thread (%d): Current semaphore value after post --> %d\n", index, my_sem_value);
    free(arg);
}


int main(void) {
    pthread_t th[NUM_THREADS];
    sem_init(&sem, 0, 4);
    for (int i = 0; i < NUM_THREADS; i++) {
        int *a = (int*)malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &func, a) != 0) {
            perror("Unable to create thread");
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Thread unable to join");
        }
    }

    sem_destroy(&sem);
}