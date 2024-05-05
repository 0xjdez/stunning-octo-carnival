

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 8
#define MAX_TASK_QUEUE_SIZE 256

static pthread_mutex_t queue_mutex;

typedef struct task_t {
    int a, b;
}task_t;

// initialize an array for task queue with
// max size
task_t task_queue[MAX_TASK_QUEUE_SIZE];
static int task_count = 0;


// this function takes a task from the task_queue
// and starts it on the a thread; it runs continually.
void *start_thread(void *arg) {
    while (1) {
        task_t task;
        // take a task from queue (in a FIFO manner) if there is a task in 
        // the task_queue.
        pthread_mutex_lock(&queue_mutex);
        if (task_count > 0 ) {
            task = task_queue[0];
            for (int i = 0; i < task_count - 1; i++) {
                task_queue[i] = task_queue[i+1];
            }
            task_count--;
        }
        pthread_mutex_unlock(&queue_mutex);
    }
}

void execute_task(task_t *task) {
    int result = task->a + task->b;
    printf("The sum of %d and %d is %d\n", task->a, task->b, result);
}

int main(void) {
    pthread_t th[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&th[i], NULL, &start_thread, NULL) != 0) {
            perror("Unable to create thread");
        }
    }
    return EXIT_SUCCESS;
}