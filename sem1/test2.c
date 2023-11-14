#include <stdio.h>
#include <stdlib.h>
#define ARR_LEN 50

int main() {
    char str[ARR_LEN];
    char *ptr = NULL;

    scanf("%s", str);
    printf("Input is %s\n", str);

    ptr = str;

    while(*ptr != '\0') {
        printf("%p --> %c\n", ptr, *ptr);
        ptr++;
    }

    return EXIT_SUCCESS;
}
