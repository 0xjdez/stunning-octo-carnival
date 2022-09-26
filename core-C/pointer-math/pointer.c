#include <stdio.h>

struct Person
{
    char name[64];
    int age;
};

typedef struct Person Person;

int main(int argc, char *argv[]) {
    Person people[100];

    Person* ptr = people;    //the name of the array is a pointer to the frist element of the array

    int i = 0;
    for (i = 0; i < 100; i++) {
        ptr->age = 0;
        ptr++; //next element in people array.
    }

    // printf("%s",);
    return 0;
}