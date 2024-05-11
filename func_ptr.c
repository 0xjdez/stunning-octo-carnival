#include <stdio.h>

// ===================int=========================


// pointer to a function that takes in an int
// and returns a void
typedef void (*int_array_mapper)(int arg);

// without typedef, this would be
// void array_map(int *arr, size_t arr_size, void (*func)(int arg));
// maps an int array to a function
void array_map(int *arr, size_t arr_size, int_array_mapper func) {
    for (size_t i = 0; i < arr_size; i++) {
        (*func)(arr[i]);
    }
}

static int s = 0;

void sum_array(int value) {
    s += value;
}

void print_array_values(int value) {
    printf("Val = %d\n", value);
}

// ==========================generic===================

typedef void (*generic_array_mapper)(void *arg);

void generic_array_map(void *arr, size_t arr_size, 
                        size_t type_size, generic_array_mapper func) {
    for (size_t i = 0; i < arr_size; i++) {
        void *type_value = arr + (i * type_size);
        (*func)(type_value);
    }
}

void generic_print_int_array_values(void *arg) {
    int *val = arg;
    printf("Val = %d\n", *val);
}

int main(void) {
    int my_array[] = {1,2,3,4,5,6,7,8,9};

    array_map(my_array, sizeof(my_array)/sizeof(int), print_array_values);
    // same as above
    generic_array_map(my_array, sizeof(my_array)/sizeof(int), sizeof(int), generic_print_int_array_values);
}