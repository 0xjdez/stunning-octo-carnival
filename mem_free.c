#include <stdio.h>
#include <stdlib.h>

/**
 * arr is a pointer to an array which is also a pointer
 * to a region in memory
*/
void process_arr(int **arr, int size) {
    // do some processing
    free(*arr);
    *arr = NULL;
}

int main(void) {
    int *arr = malloc(sizeof(int) * 10);
    process_arr(&arr, 10);
    free(arr);
    arr = NULL;
}