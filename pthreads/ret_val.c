#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *roll_dice() {
    int value = (rand() % 6) + 1;
    int *result = malloc(sizeof(int));
    *result = value;
    // for debugging
    printf("Thread result address: %p\n", result);
    return (void*)result;
}


int main(void) {
    pthread_t th;
    srand(time(NULL));
    int *res;
    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
        perror("Unable to create thread");
    }

    if (pthread_join(th, (void**)&res) != 0) {
        perror("Thread unable to join");
    }
    
    printf("Random number: %d\n", *res);
    printf("Main thread result address: %p\n", res);
    free(res);
    return 0;
}