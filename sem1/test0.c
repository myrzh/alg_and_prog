#include <stdio.h>

int main() {
    char name[] = "Ivan";
    unsigned short int age;
    age = 17;
    printf("Hello world, my name is %s, my age is %hu\n", name, age);
    printf("Thanos\n");

    long long first_number, second_number, result;
    first_number = 2435234;
    second_number = 324;
    result = first_number + second_number;
    printf("%lld\n", result);
    return 0;
}
