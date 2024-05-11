#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "utils.h"


int main(void) {
    Point_t* a = prac_oom_guard(malloc(sizeof(Point_t)));
    *a = prac_point_init(1.0, 2.0);

    prac_point_print(a);
}