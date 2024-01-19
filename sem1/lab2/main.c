#include <stdio.h>
#include <math.h>
#include <time.h>

void calc_int() {
    int variable;
    void *p1, *p2;
    p1 = &variable;
    p2 = (&variable) + 1;
    long size = p2 - p1;

    int max = pow(2, size * 8 - 1) - 1;
    int min = max + 1;
    
    printf("int: %ld, %d, %d\n", size, max, min);
}

void calc_short_int() {
    short int variable;
    void *p1, *p2;
    p1 = &variable;
    p2 = (&variable) + 1;
    long size = p2 - p1;

    short int max = pow(2, size * 8 - 1) - 1;
    short int min = max + 1;

    printf("short int: %ld, %hi, %hi\n", size, max, min);
}

void calc_unsigned_short_int() {
    unsigned short int variable;
    void *p1, *p2;
    p1 = &variable;
    p2 = (&variable) + 1;
    long size = p2 - p1;

    unsigned short int max = pow(2, size * 8) - 1;
    unsigned short int min = max + 1;
    printf("unsigned short int: %ld, %hu, %hu\n", size, max, 0);
}

void calc_char() { // we are talking about signed char, right?
    signed char variable;
    void *p1, *p2;
    p1 = &variable;
    p2 = (&variable) + 1;
    long size = p2 - p1;
    
    signed char max = pow(2, size * 8 - 1) - 1;
    signed char min = max + 1;

    printf("char: %ld, %hhi, %hhi\n", size, max, min);
}

void calc_unsigned_char() {
    unsigned char variable;
    void *p1, *p2;
    p1 = &variable;
    p2 = (&variable) + 1;
    long size = p2 - p1;

    unsigned char max = pow(2, size * 8) - 1;
    unsigned char min = max + 1;

    printf("unsigned char: %ld, %hhu, %hhu\n", size, max, min);
}

void calc_unsigned_int() {
    unsigned int variable;
    void *p1, *p2;
    p1 = &variable;
    p2 = (&variable) + 1;
    long size = p2 - p1;
    
    unsigned int max = pow(2, size * 8) - 1;
    unsigned int min = max + 1;

    printf("unsigned int: %ld, %u, %u\n", size, max, min);
}

void calc_unsigned_long_long_int() {
    unsigned long long int variable;
    void *p1, *p2;
    p1 = &variable;
    p2 = (&variable) + 1;
    long size = p2 - p1;

    // unsigned long long int max = (unsigned long long int) (pow(2, size * 8) - 1); // idk why there's any need to specify right expression value
    unsigned long long int max = (pow(2, size * 8) - 1); // idk why there's any need to specify right expression value
    unsigned long long int min = max + 1;

    printf("unsigned long long int: %ld, %llu, %llu\n", size, max, min);
}

void calc_float() {
    float variable;
    void *p1, *p2;
    p1 = &variable;
    p2 = (&variable) + 1;
    long size = p2 - p1;

    printf("float: %ld\n", size);
}

void calc_double() {
    double variable;
    void *p1, *p2;
    p1 = &variable;
    p2 = (&variable) + 1;
    long size = p2 - p1;

    printf("double: %ld\n", size);
}

int main() {
    clock_t t;
    t = clock();

    calc_int();
    calc_short_int();
    calc_unsigned_short_int();
    calc_char();
    calc_unsigned_char();
    calc_unsigned_int();
    calc_unsigned_long_long_int();
    calc_float();
    calc_double();

    t = clock() - t;
    double timeTaken = ((double)t) / CLOCKS_PER_SEC;

    printf("script took %f seconds to execute\n", timeTaken);
    return 0;
}
