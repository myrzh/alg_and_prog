#include <stdio.h>

#define MAX_LENGTH 35

// Функция для проверки, является ли заданная подстрока палиндромом
int isPalindrome(char str[], int start, int end) {
    if (start >= end) {
        return 1;
    }
    if (str[start] != str[end]) {
        return 0;
    }
    return isPalindrome(str, start + 1, end - 1);
}

// Рекурсия для поиска максимального полиндрома
void findLongestPalindrome(char str[], int length, int *maxStart, int *maxEnd, int start) {
    if (start >= length) {
        return;
    }

    for (int end = length - 1; end > start; end--) {
        if (isPalindrome(str, start, end)) {
            if ((end - start) > (*maxEnd - *maxStart)) {
                *maxStart = start;
                *maxEnd = end;
            }
            break; // Прерывание для получения maxEnd
        }
    }

    findLongestPalindrome(str, length, maxStart, maxEnd, start + 1);
}

int main() {
    char input[MAX_LENGTH + 1]; // +1 для учета символа завершения строки
    printf("Enter the string (max. 35 characters):");
    scanf("%s", input);

    int maxStart = 0, maxEnd = 0;
    int length = 0;
    while (input[length] != '\0') {
        length++;
    }

    findLongestPalindrome(input, length, &maxStart, &maxEnd, 0);

    printf("Finded max polindrom: ");
    for (int i = maxStart; i <= maxEnd; i++) {
        printf("%c", input[i]);
    }
    printf("\nWhich characters and at which positions should be removed to obtain the maximum palindrome:\n");
    for (int i = 0; i < length; i++) {
        if (i < maxStart || i > maxEnd) {
            printf("%d - %c\n", i, input[i]);
        }
    }

    return 0;
}
