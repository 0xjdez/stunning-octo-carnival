#include <stdio.h>
// #include <malloc.h>
#include <stdlib.h>


typedef struct point {
    float x;
    float y;
    float z;
} point_t;

point_t* init_coord(float x, float y, float z) {
    point_t* ptr  = (point_t*)malloc(sizeof(point_t));
    ptr->x = x;
    ptr->y = y;
    ptr->z = z;

    return ptr;
}

point_t* add_points(point_t* p1, point_t* p2) {
    point_t* result;
    result->x = p1->x + p2->x;
    result->y = p1->y + p2->y;
    result->z = p1->z + p2->z;

    return result;
}


int main() {
    point_t* first_coord = init_coord(1.0, 2.0, 3.0);

    point_t* second_coord = init_coord(2.0, 3.0, 4.0);

    point_t* new_coord = add_points(first_coord, second_coord);
    printf("%f, %f, %f\n", new_coord->x, new_coord->y, new_coord->z);
    printf("%ld\n", sizeof(point_t));
    printf("%ld\n", sizeof(char));

    free(first_coord);
    free(second_coord);

    return 0;

}