#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_LEN 10
#define MAX_NAME_DB 51
#define MAX_NORMALIZEDPHONE_DB 12
#define MAX_PRETTYPHONE_DB 19
#define MAX_PHONE_INPUT 100

struct Contact {
        char name0[MAX_NAME_DB];
        char name1[MAX_NAME_DB];
        char name2[MAX_NAME_DB];
        char name3[MAX_NAME_DB];
        char name4[MAX_NAME_DB];
        char name5[MAX_NAME_DB];
        char name6[MAX_NAME_DB];
        char normalizedPhone[MAX_NORMALIZEDPHONE_DB];
        char prettyPhone[MAX_PRETTYPHONE_DB];
    };

struct Contact contacts[DB_LEN];

void dbFill() {
    strcpy(contacts[0].name0, "Ivanov Ivan Ivanovich");
    strcpy(contacts[0].name1, "Ivanov Ivan");
    strcpy(contacts[0].name2, "Ivan Ivanovich");
    strcpy(contacts[0].name3, "Ivanov Ivanovich");
    strcpy(contacts[0].name4, "Ivanov");
    strcpy(contacts[0].name5, "Ivan");
    strcpy(contacts[0].name6, "Ivanovich");
    strcpy(contacts[0].normalizedPhone, "79818883322");
    strcpy(contacts[0].prettyPhone, "+7 (981) 888-33-22");

    strcpy(contacts[1].name0, "Kirillov Anton Efimovich");
    strcpy(contacts[1].name1, "Kirillov Anton");
    strcpy(contacts[1].name2, "Anton Efimovich");
    strcpy(contacts[1].name3, "Kirillov Efimovich");
    strcpy(contacts[1].name4, "Kirillov");
    strcpy(contacts[1].name5, "Anton");
    strcpy(contacts[1].name6, "Efimovich");
    strcpy(contacts[1].normalizedPhone, "79998881100");
    strcpy(contacts[1].prettyPhone, "+7 (999) 888-11-00");
    
    strcpy(contacts[2].name0, "Afanasieva Olga");
    strcpy(contacts[2].name1, "");
    strcpy(contacts[2].name2, "");
    strcpy(contacts[2].name3, "");
    strcpy(contacts[2].name4, "Afanasieva");
    strcpy(contacts[2].name5, "Olga");
    strcpy(contacts[2].name6, "");
    strcpy(contacts[2].normalizedPhone, "79813451122");
    strcpy(contacts[2].prettyPhone, "+7 (981) 345-11-22");

    strcpy(contacts[3].name0, "Lermontov Mikhail Yurievich");
    strcpy(contacts[3].name1, "Lermontov Mikhail");
    strcpy(contacts[3].name2, "Mikhail Yurievich");
    strcpy(contacts[3].name3, "Lermontov Yurievich");
    strcpy(contacts[3].name4, "Lermontov");
    strcpy(contacts[3].name5, "Mikhail");
    strcpy(contacts[3].name6, "Yurievich");
    strcpy(contacts[3].normalizedPhone, "79008765431");
    strcpy(contacts[3].prettyPhone, "8 (900) 876-54-31");

    strcpy(contacts[4].name0, "Pushkin Alexander Sergeevich");
    strcpy(contacts[4].name1, "Pushkin Alexander");
    strcpy(contacts[4].name2, "Alexander Sergeevich");
    strcpy(contacts[4].name3, "Pushkin Sergeevich");
    strcpy(contacts[4].name4, "Pushkin");
    strcpy(contacts[4].name5, "Alexander");
    strcpy(contacts[4].name6, "Sergeevich");
    strcpy(contacts[4].normalizedPhone, "71119876521");
    strcpy(contacts[4].prettyPhone, "+7 (111) 987-65-21");

    strcpy(contacts[5].name0, "Fet Afanasy Afanasyevich");
    strcpy(contacts[5].name1, "Fet Afanasy");
    strcpy(contacts[5].name2, "Afanasy Afanasyevich");
    strcpy(contacts[5].name3, "Fet Afanasyevich");
    strcpy(contacts[5].name4, "Fet");
    strcpy(contacts[5].name5, "Afanasy");
    strcpy(contacts[5].name6, "Afanasyevich");
    strcpy(contacts[5].normalizedPhone, "70002345434");
    strcpy(contacts[5].prettyPhone, "8 (000) 234-54-34");

    strcpy(contacts[6].name0, "Euclid");
    strcpy(contacts[6].name1, "");
    strcpy(contacts[6].name2, "");
    strcpy(contacts[6].name3, "");
    strcpy(contacts[6].name4, "");
    strcpy(contacts[6].name5, "Euclid");
    strcpy(contacts[6].name6, "");
    strcpy(contacts[6].normalizedPhone, "71234567899");
    strcpy(contacts[6].prettyPhone, "+7 (123) 456-78-99");
    
    strcpy(contacts[7].name0, "Tannhaus H.G.");
    strcpy(contacts[7].name1, "");
    strcpy(contacts[7].name2, "");
    strcpy(contacts[7].name3, "");
    strcpy(contacts[7].name4, "Tannhaus");
    strcpy(contacts[7].name5, "H.G.");
    strcpy(contacts[7].name6, "");
    strcpy(contacts[7].normalizedPhone, "73333333333");
    strcpy(contacts[7].prettyPhone, "+7 (333) 333-33-33");
    
    strcpy(contacts[8].name0, "Brando Marlon");
    strcpy(contacts[8].name1, "");
    strcpy(contacts[8].name2, "");
    strcpy(contacts[8].name3, "");
    strcpy(contacts[8].name4, "Brando");
    strcpy(contacts[8].name5, "Marlon");
    strcpy(contacts[8].name6, "");
    strcpy(contacts[8].normalizedPhone, "79826242638");
    strcpy(contacts[8].prettyPhone, "+7 (982) 624-26-38");
    
    strcpy(contacts[9].name0, "Polanski Roman");
    strcpy(contacts[9].name1, "");
    strcpy(contacts[9].name2, "");
    strcpy(contacts[9].name3, "");
    strcpy(contacts[9].name4, "Polanski");
    strcpy(contacts[9].name5, "Roman");
    strcpy(contacts[9].name6, "");
    strcpy(contacts[9].normalizedPhone, "71053536523");
    strcpy(contacts[9].prettyPhone, "+7 (105) 353-65-23");
}


void normalizeInput(char *str, const char *charsToRemove) {
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

    const char charsToRemove[] = "+\n";
    char inputString[MAX_PHONE_INPUT];
    short int lookforNumber = 0;
    short int recordFound = 0;

    fgets(inputString, sizeof(inputString), stdin);
    normalizeInput(inputString, charsToRemove);

    if (isStringOnlyDigits(inputString)) {
        lookforNumber = 1;
    }

    for (int i = 0; i < DB_LEN; i++) {
        if (lookforNumber == 1) {
            if (strcmp(contacts[i].normalizedPhone, inputString) == 0) {
                printf("Found, %s, %s.\n", contacts[i].name0, contacts[i].prettyPhone);
                recordFound = 1;
                break;
            }
        } else {
            char lastName[50];
            char firstName[50];
            char middleName[50];

            // if ((strstr(contacts[i].name0, inputString) != NULL && strcmp(contacts[i].name0, "") != 0) ||
            //     (strstr(contacts[i].name1, inputString) != NULL && strcmp(contacts[i].name1, "") != 0) ||
            //     (strstr(contacts[i].name2, inputString) != NULL && strcmp(contacts[i].name2, "") != 0) ||
            //     (strstr(contacts[i].name3, inputString) != NULL && strcmp(contacts[i].name3, "") != 0) ||
            //     (strstr(contacts[i].name4, inputString) != NULL && strcmp(contacts[i].name4, "") != 0) ||
            //     (strstr(contacts[i].name5, inputString) != NULL && strcmp(contacts[i].name5, "") != 0) ||
            //     (strstr(contacts[i].name6, inputString) != NULL && strcmp(contacts[i].name6, "") != 0)) {
            //     printf("Found, %s, %s.\n", contacts[i].name0, contacts[i].prettyPhone);
            //     recordFound = 1;
            //     break;
            // }
        }
    }

    if (!recordFound) {
        printf("%s\n", "Not found.");
    }

    return 0;
}
