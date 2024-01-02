#include <stdio.h>

int strlen(char *s) {
	int count = 0;
	while (*s != '\0') {
    	count++;
        s += sizeof(char);
    }
    return count;
}

int a = 5;
int* b = &a;
*b = 4;

char c = 'c';
char* pc = &c;
c = 'a';
*pc = 'b';

char *strcpy(char *s1, char *s2) {
	char *s1_ptr = s1;
	if (strlen(s1) >= strlen(s2)) {
    	while (*s2) {
        	*s1 = *s2;
            s1 += sizeof(char);
            s2 += sizeof(char);
        }
    }
    return s1_ptr;
}

while(*s1++=*s2++)

int main()
{
	char str[] = "test string\0";
    printf("%lu\n", sizeof(str));
    char str1[5] = { 't', 'e', 's', 't', '0' };
    printf("%lu\n", sizeof(str1));
	return 0;
}
