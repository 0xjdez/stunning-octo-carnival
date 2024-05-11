#include <stdlib.h>     // NULL
#include <stdio.h>      // fprintf, stderr
#include "utils.h"

void* prac_oom_guard(void* ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    return ptr;
}