#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a; // goes into the stack
    printf("Enter the size of array\n");
    scanf("%d", &a);

    int* p = malloc(a*sizeof(int));
    for (int i = 0; i < a; i++)
    {
        p[i] = i + 1;
    }
    
    for (int i = 0; i < a; i++)
    {
        printf("%d ", p[i]);
    }
    free(p);


    p = calloc(a, sizeof(int));
    for (int i = 0; i < a; i++)
    {
        p[i] = i + 1;
    }
   
    for (int i = 0; i < a; i++)
    {
        printf("%d", p[i]);
    }
     free(p);
}