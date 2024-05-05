#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct custom_float {
    bool is_ext;
    union {
        float fl;
        double fl_ext;
    }; 
} custom_float;

int main(void) {
    custom_float cf, cf2;
    cf.is_ext = false;
    cf2.is_ext = true;

    cf.fl = 12.5f;
    cf2.fl_ext = 1222.555f;

    printf("%f %lf\n", cf.fl, cf2.fl_ext);
    printf("%f %lf\n", cf.fl_ext, cf2.fl);
}