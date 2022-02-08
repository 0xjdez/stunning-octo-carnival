#include <stdio.h>
#define ARRAY_SIZE 5
/*
Structures (struct) are user-defined data type in C 
*/

// struct point
// {
//     int x;
//     int y;
// };

// point3D struct declaration.
struct point3D {
    int x, y, z;
};

int main(){
    // struct point p2 = {10, 20};
    // printf("%d, %d\n", p2.x, p2.y);

    // struct point *p = &p2;
    // printf("%d, %d\n", p->x, p->y);

    struct point3D p1 = {.z = 4, .y = 5, .x = 3};
    struct point3D *p12 = &p1;

    struct point3D arr[ARRAY_SIZE];

    int j = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i].x = j;
        arr[i].y = j+1;
        arr[i].z = j+2;
        j++;
    }
    

    for (int i = 0; i < 5; i++)
    {
        printf("x = %d\ny = %d\nz = %d\n", arr[i].x, arr[i].y, arr[i].z);
        printf("after iteration %d....\n", i+1);
    }
    

}