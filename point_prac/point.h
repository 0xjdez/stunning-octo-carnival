#ifndef PRAC_POINT_H
#define PRAC_POINT_H

typedef struct Point_s {
    double x;
    double y;
} Point_t;

/**
 * Initialize and return a point
*/
Point_t prac_point_init(double x, double y);

/**
 * Print a representation of a point
*/
void prac_point_print(const Point_t* p);

#endif