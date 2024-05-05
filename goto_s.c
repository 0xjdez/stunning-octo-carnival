#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sum_to_first_nan(double *vector, size_t vector_size,
                        double *vector2, size_t vector2_size,
                        int *error) {
    double sum = 0;
    *error = 1;

    for (size_t i = 0; i < vector_size; i++) {
        if (isnan(vector[i])) goto outro;
        sum += vector[i];
    }

    for (size_t i = 0; i < vector2_size; i++) {
        if (isnan(vector2[i])) goto outro;
        sum += vector2[i];
    }
    
    outro:
    printf("Encountered a nan. Sum is: %g\n", sum);
    free(vector);
    free(vector2);
    return sum;
}

int main() {
    
}