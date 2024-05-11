#include <stdio.h>

// int main() {
//     char start = '.';
//     char* hero = &start;

//     while(1) {
//         if (*hero == '\0') {
//             putchar('\n');
//         }
//         putchar(*hero);
//         fflush(stdout);
//         hero++;
//     }
// }

int main(int argc, char** argv, char** env){
    // for (int i = 0; i < argc; i++) {
    //     printf("%s\n", *(argv + i));
    // }

    while (*argv != NULL) {
        printf("%s\n", *argv++);
    }

    while (*env != NULL) {
        printf("%s\n", *env++);
    }
}