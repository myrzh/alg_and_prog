#include <stdio.h>

int main() {
    int count = 0;
    int i;
    int k = 0;

    while(count <= 100) {
        // printf("%d\n", count++);
    }

    for(i = 0; i <= 100; i++) {
        // printf("%d\n", i);
    }

    do {
        // printf("%d\n", k++);
    } while (k <= 100);

    unsigned short int age = 90;
    if (age < 18) {
        printf("NO");
    } else if (age > 90) {
        printf("NO");
    } else if (age > 18 && age < 90) {
        printf("YES");
    } else {
        printf("ERROR");
    }
    
    age = 90;
    switch (age)
    {
    case 18:
        /* code */
        break;
    
    default:
        break;
    }

    int ret_status = age == 90 ? -1 : 0;
    return 0;
}
