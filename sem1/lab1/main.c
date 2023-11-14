#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_LEN 10
#define MAX_NAME_DB 51
#define MAX_PHONE_DB 12
#define MAX_PHONE_INPUT 100

void dbInit() {
    struct Contact {
        char name[MAX_NAME_DB];
        char number[MAX_PHONE_DB];
    };

    struct Contact contacts[DB_LEN];

    strcpy(contacts[0].name, "Ivanov Ivan Ivanovich");
    strcpy(contacts[0].number, "79818883322");

    strcpy(contacts[1].name, "Kirillov Anton Efimovich");
    strcpy(contacts[1].number, "79998881100");
    
    strcpy(contacts[2].name, "Afanasieva Olga");
    strcpy(contacts[2].number, "79813451122");

    strcpy(contacts[3].name, "Lermontov Mikhail Yurievich");
    strcpy(contacts[3].number, "79008765431");

    strcpy(contacts[4].name, "Pushkin Alexander Sergeevich");
    strcpy(contacts[4].number, "71119876521");

    strcpy(contacts[4].name, "Fet Afanasy Afanasyevich");
    strcpy(contacts[4].number, "70002345434");

    strcpy(contacts[5].name, "Euclid");
    strcpy(contacts[5].number, "71234567899");

}


void normalizePhone(char *str, const char *charsToRemove) {
    int i, j;
    int len = strlen(str);
    int charsToRemoveLen = strlen(charsToRemove);

    for (i = j = 0; i < len; ++i) {
        int removeChar = 0;
        for (int k = 0; k < charsToRemoveLen; ++k) {
            if (str[i] == charsToRemove[k]) {
                removeChar = 1;
                break;
            }
        }

        if (!removeChar) {
            str[j++] = str[i];
        }
    }

    str[j] = '\0';
}


int main() {
    dbInit();

    const char charsToRemove[] = " \t+-[]()";
    char inputString[MAX_PHONE_INPUT];
    fgets(inputString, sizeof(inputString), stdin);
    normalizePhone(inputString, charsToRemove);
    printf("You entered: %s\n", inputString);
    return 0;
}
