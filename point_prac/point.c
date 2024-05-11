#include <stdio.h>      // printf
#include "point.h"

Point_t prac_point_init(double x, double y) {
    Point_t p = {x,y};
    return p;
}

void prac_point_print(const Point_t* p) {
    printf("Point {%f, %f}\n", p->x, p->y);
}