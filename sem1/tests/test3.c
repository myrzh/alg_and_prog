#include <stdio.h>
#include <string.h>

int main() {

    char inputString[50];
    fgets(inputString, sizeof(inputString), stdin);

    char lastName[50];
    char firstName[50];
    char middleName[50];
    const char space = ' ';
    int firstSpace = 0;
    int secondSpace = 0;

    for (int i = 0; i < strlen(inputString); i++) {
        if (strcmp(&inputString[i], space) != 0 && !firstSpace && !secondSpace) {
            strcat(lastName, &inputString[i]);
        } else if (strcmp(&inputString[i], space) != 0 && firstSpace && !secondSpace) {
            strcat(lastName, &inputString[i]);
        } else if (strcmp(&inputString[i], space) != 0 && firstSpace && secondSpace) {
            strcat(middleName, &inputString[i]);
        } else if (strcmp(&inputString[i], space) == 0 && !firstSpace && !secondSpace) {
            firstSpace = 1;
        } else if (strcmp(&inputString[i], space) == 0 && firstSpace && !secondSpace) {
            secondSpace = 1;
        }
    }

    strcat(lastName, '\0');
    strcat(firstName, '\0');

    printf("%s\n%s\n%s\n", lastName, firstName, middleName);
}
