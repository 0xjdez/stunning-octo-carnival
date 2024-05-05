

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 8
#define MAX_TASK_QUEUE_SIZE 256

typedef struct task_t {
    int a, b;
}task_t;

// initialize an array for task queue with
// max size
task_t task_queue[MAX_TASK_QUEUE_SIZE];
static int task_count = 0;

void *start_thread(void *arg) {

}

void execute_task(task_t *task) {
    int result = task->a + task->b;
    printf("The sum of %d and %d is %d\n", task->a, task->b, result);
}

int main(void) {
    task_t task = {
        .a = 10, .b = 20
    };

    execute_task(&task);

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&th[i], NULL, &start_thread, NULL) != 0) {
            perror("Unable to create thread
            ")
        }
    }
    return EXIT_SUCCESS;
}