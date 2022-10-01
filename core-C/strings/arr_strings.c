#include <stdio.h>

int main(void)
{

    char stuff[][10] = {"mangoes", "tomatoes", "Melon"};    // wastes space
    char *stuffs[] = {"mangoes", "tomatoes", "Melon", "Fish"};  // better (array of pointers)
    return 0;
}