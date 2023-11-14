#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_LEN 10
#define MAX_NAME_DB 51
#define MAX_NORMALIZEDPHONE_DB 12
#define MAX_PRETTYPHONE_DB 19
#define MAX_PHONE_INPUT 100

struct Contact {
        char name[MAX_NAME_DB];
        char normalizedPhone[MAX_NORMALIZEDPHONE_DB];
        char prettyPhone[MAX_PRETTYPHONE_DB];
    };

struct Contact contacts[DB_LEN];

void dbFill() {
    strcpy(contacts[0].name, "Ivanov Ivan Ivanovich");
    strcpy(contacts[0].normalizedPhone, "79818883322");
    strcpy(contacts[0].prettyPhone, "+7 (981) 888-33-22");

    strcpy(contacts[1].name, "Kirillov Anton Efimovich");
    strcpy(contacts[1].normalizedPhone, "79998881100");
    strcpy(contacts[1].prettyPhone, "+7 (999) 888-11-00");
    
    strcpy(contacts[2].name, "Afanasieva Olga");
    strcpy(contacts[2].normalizedPhone, "79813451122");
    strcpy(contacts[2].prettyPhone, "+7 (981) 345-11-22");

    strcpy(contacts[3].name, "Lermontov Mikhail Yurievich");
    strcpy(contacts[3].normalizedPhone, "79008765431");
    strcpy(contacts[3].prettyPhone, "8 (900) 876-54-31");

    strcpy(contacts[4].name, "Pushkin Alexander Sergeevich");
    strcpy(contacts[4].normalizedPhone, "71119876521");
    strcpy(contacts[4].prettyPhone, "+7 (111) 987-65-21");

    strcpy(contacts[4].name, "Fet Afanasy Afanasyevich");
    strcpy(contacts[4].normalizedPhone, "70002345434");
    strcpy(contacts[4].prettyPhone, "8 (000) 234-54-34");

    strcpy(contacts[5].name, "Euclid");
    strcpy(contacts[5].normalizedPhone, "71234567899");
    strcpy(contacts[5].prettyPhone, "+7 (123) 456-78-99");
    
    strcpy(contacts[6].name, "H.G. Tannhaus");
    strcpy(contacts[6].normalizedPhone, "73333333333");
    strcpy(contacts[6].prettyPhone, "+7 (333) 333-33-33");
    
    strcpy(contacts[7].name, "Marlon Brando");
    strcpy(contacts[7].normalizedPhone, "79826242638");
    strcpy(contacts[7].prettyPhone, "+7 (982) 624-26-38");
    
    strcpy(contacts[8].name, "Roman Polanski");
    strcpy(contacts[8].normalizedPhone, "71053536523");
    strcpy(contacts[8].prettyPhone, "+7 (105) 353-65-23");
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

    if (str[0] == '8') {
        str[0] = '7';
    }
}

int isStringOnlyDigits(const char *str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }
    return 1;
}

int main() {
    dbFill();

    const char charsToRemove[] = " \t\n+-()";
    char inputString[MAX_PHONE_INPUT];
    short int lookforNumber = 0;
    short int recordFound = 0;

    fgets(inputString, sizeof(inputString), stdin);
    normalizePhone(inputString, charsToRemove);

    if (isStringOnlyDigits(inputString)) {
        lookforNumber = 1;
    }

    for (int i = 0; i <= 5; i++) {
        if (lookforNumber == 1) {
            if (strcmp(contacts[i].normalizedPhone, inputString) == 0) {
                printf("Found, %s, %s.\n", contacts[i].name, contacts[i].prettyPhone);
                recordFound = 1;
                break;
            }
        } else {
            if (strcmp(contacts[i].name, inputString) == 0) {
                printf("Found, %s, %s.\n", contacts[i].name, contacts[i].prettyPhone);
                recordFound = 1;
                break;
            }
        }
    }

    if (!recordFound) {
        printf("%s\n", "Not found.");
    }

    return 0;
}
