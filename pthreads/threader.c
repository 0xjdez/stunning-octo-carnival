

#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 4

void *thread_func(void *p_arg) {
    // // cast arg to int pointer
    // int *p = (int*)p_arg;
    // // dereference arg
    // int num = *p;
    // shorter method
    int num = *(int*)p_arg;
    printf("Thread number %d\n", num);
    return 0;
}


int main(void) {
    int t_num[NUM_THREADS];
    int i;
    // create 4 thread variables
    pthread_t tid[NUM_THREADS];
    // threads start running immediately after their creation
    for (i = 0; i < NUM_THREADS; i++) {
        t_num[i] = i;
        pthread_create(&tid[i], NULL, &thread_func, &t_num[i]);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}