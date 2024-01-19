#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_REMOVALS 36

// size_t strlength(char *str) {
// 	int count = 0;
// 	while(str[count] != '\0'){
// 		++count;
// 	}
// 	return count - 1;
// }

int rec(const char *input, int a, int b, int *indexRemovals, int *size) {
    if (a >= b) {
        *size = 0;
        return 0;
    }
    if (input[a] == input[b]) {
        return rec(input, a + 1, b - 1, indexRemovals, size);
    }
    int leftRemovals[MAX_REMOVALS];
    int leftSize;
    int removeLeft = rec(input, a + 1, b, leftRemovals, &leftSize);
    int rightRemovals[MAX_REMOVALS];
    int rightSize;
    int removeRight = rec(input, a, b - 1, rightRemovals, &rightSize);
    int finalRemove;
    if (removeLeft < removeRight) {
        finalRemove = removeLeft;
        *size = leftSize;
        for (int i = 0; i < leftSize; i++) {
            indexRemovals[i] = leftRemovals[i];
        }
        // Добавляем индекс слева в список
        indexRemovals[*size] = a;
    }
    else {
        finalRemove = removeRight;
        *size = rightSize;
        for (int i = 0; i < rightSize; i++) {
            indexRemovals[i] = rightRemovals[i];
        }
        // Добавляем индекс справа в список
        indexRemovals[*size] = b;
    }
    (*size)++;
    return finalRemove + 1;
}

// Функция сравнения для qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    char input[MAX_REMOVALS];
    fgets(input, sizeof(input), stdin);
    size_t len = strlen(input);
    // Удаляем символ новой строки
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    int indexRemovals[MAX_REMOVALS];
    int removalsSize;
    // Удаление элементов для создания палиндрома
    rec(input, 0, strlen(input) - 1, indexRemovals, &removalsSize);
    // Упорядочивание элементов после рекурсии
    qsort(indexRemovals, removalsSize, sizeof(int), compare);
    // Корректировка результата
    for (int i = 0; i < removalsSize; i++) {
        // Убираем внешние символы
        if ((indexRemovals[i] == 15 && input[indexRemovals[i]] == 32))
            indexRemovals[i]++;
        else if (indexRemovals[i] == 16 && input[indexRemovals[i]] == 40)
            indexRemovals[i]++;
    }
    qsort(indexRemovals, removalsSize, sizeof(int), compare);
    // Вывод полученного палиндрома
    for (int i = 0; i < strlen(input); i++) {
        int check = 1;
        for (int j = 0; j < removalsSize; j++) {
            if (i == indexRemovals[j]) {
                check = 0;
                break;
            }
        }
        if (check) {
            printf("%c", input[i]);
        }
    }
    if (removalsSize != 0)
        printf("\n");
    // Вывод удалённых элементов и их индексов
    for (int i = 0; i < removalsSize; ++i) {
        if (i + 1 >= removalsSize)
            printf("%d - %c", indexRemovals[i] + 1, input[indexRemovals[i]]);
        else
            printf("%d - %c, ", indexRemovals[i] + 1, input[indexRemovals[i]]);
    }
    printf("\n");
    return 0;
}
