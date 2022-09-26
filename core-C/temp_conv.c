#include <stdio.h>

/*
print Fahrenheit-Celcius table
for fahr = 0,20,40....,300
*/
#define UPPER 300
#define LOWER 0
#define STEP 20


int main(){

    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP){
        printf("%3d\t%6.2f\n", fahr, ((5.0/9.0)*(fahr-32)));
    }
}