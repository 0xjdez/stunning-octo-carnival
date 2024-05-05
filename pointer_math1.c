#include <stdio.h>
typedef char* string;

int main(void) {
    // char *list[] = {"first", "second", "third", NULL};
    // for (char **p = list; *p != NULL; p++) {
    //     printf("%s\n", *p);
    // }

    // clearer code using typedef
    string list[] = {"first", "second", "third", NULL};
    for (string *p = list; *p != NULL; p++) {
        printf("%s\n", *p);
    }
}