#include <assert.h>
#include <string.h>

int main(void) {
    int abc[] = {1,2,3};
    int *copy1, copy2[3];

    copy1 = abc;

    memmove(copy2, abc, sizeof(int)*3);

    abc[0] = 3;

    assert(copy1[0] == 3);
    assert(copy2[0] == 0);
}