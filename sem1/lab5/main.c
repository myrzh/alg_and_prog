#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct sortStats {
    int comparisons;
    int swaps;
} stats;

stats quickSortStats;

void quickSort(int array[25], int first, int last) {
    int i;
    int j;
    int pivot;
    int temp;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (array[i] <= array[pivot] && i < last) {
                i++;
            }
            while (array[j] > array[pivot]) {
                j--;
            }
            quickSortStats.comparisons += 1;
            if (i < j) {
                quickSortStats.swaps += 1;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        quickSortStats.swaps += 1;
        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;
        quickSort(array, first, j - 1);
        quickSort(array, j + 1, last);
    }
}


stats shakerSort(int array[], int n) {   
    int comparisons = 0;
    int swaps = 0;
    int temp;

    for (int i = 1; i <= n / 2; i++) {
        for (int j = i - 1; j < n - i; j++) {
            comparisons += 1;
            if (array[j] > array[j+1]) {
                swaps += 1;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        for (int j = n - i - 1; j >= i; j--) {
            comparisons += 1;
            if (array[j] < array[j-1]) {
                swaps += 1;
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }

    stats shakerSortStats;
    shakerSortStats.comparisons = comparisons;
    shakerSortStats.swaps = swaps;
    return shakerSortStats;
}

stats bubbleSort(int array[], int n) {
    int comparisons = 0;
    int swaps = 0;
    int temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons += 1;
            if (array[j] > array[j + 1]) {
                swaps += 1;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    stats bubbleSortStats;
    bubbleSortStats.comparisons = comparisons;
    bubbleSortStats.swaps = swaps;
    return bubbleSortStats;
}

int main() {
    clock_t start;
    clock_t end;

    char filename[100] = "numbers.txt";
    char line[70000];

    // printf("Enter the filename: ");
    // scanf("%s", filename);
    // strcpy(filename, "numbers_small.txt");

    FILE *f_input = fopen(filename, "r");
    fgets(line, sizeof(line), f_input);
    fclose(f_input);

    char *token = strtok(line, ", ");
    int numbers[100000];
    int n = 0;
    while (token != NULL) {
        numbers[n] = atoi(token);
        token = strtok(NULL, ", ");
        n++;
    }
    
    const int array_len = n;
    int array_quick[array_len];
    int array_shaker[array_len];
    int array_bubble[array_len];

    for (int i = 0; i < array_len; i++) {
        array_quick[i] = numbers[i];
        array_shaker[i] = numbers[i];
        array_bubble[i] = numbers[i];
    }

    quickSortStats.comparisons = 0;
    quickSortStats.swaps = 0;
    start = clock();
    quickSort(array_quick, 0, array_len - 1);
    end = clock();
    int quick_time = (int)((float)(end - start) / CLOCKS_PER_SEC * 1000);

    start = clock();
    stats shakerSortStats = shakerSort(array_shaker, array_len);
    end = clock();
    int shaker_time = (int)((float)(end - start) / CLOCKS_PER_SEC * 1000);

    start = clock();
    stats bubbleSortStats = bubbleSort(array_bubble, array_len);
    end = clock();
    int bubble_time = (int)((float)(end - start) / CLOCKS_PER_SEC * 1000);

    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Format the current time
    char formattedTime[100];
    strftime(formattedTime, sizeof(formattedTime), "%M_%H_%d_%m_%y", timeinfo);

    char quick_filename[50] = "result_";
    strcat(quick_filename, formattedTime);
    strcat(quick_filename, "_quicksort.txt");
    FILE *f_quick = fopen(quick_filename, "w");
    for (int i = 0; i < array_len; i++) {
        if (i > 0) {
            fprintf(f_quick, ", ");
        }
        fprintf(f_quick, "%d", array_quick[i]);
    }
    fclose(f_quick);

    char shaker_filename[50] = "result_";
    strcat(shaker_filename, formattedTime);
    strcat(shaker_filename, "_shakersort.txt");
    FILE *f_shaker = fopen(shaker_filename, "w");
    for (int i = 0; i < array_len; i++) {
        if (i > 0) {
            fprintf(f_shaker, ", ");
        }
        fprintf(f_shaker, "%d", array_shaker[i]);
    }
    fclose(f_shaker);

    char bubble_filename[50] = "result_";
    strcat(bubble_filename, formattedTime);
    strcat(bubble_filename, "_bubblesort.txt");
    FILE *f_bubble = fopen(bubble_filename, "w");
    for (int i = 0; i < array_len; i++) {
        if (i > 0) {
            fprintf(f_bubble, ", ");
        }
        fprintf(f_bubble, "%d", array_shaker[i]);
    }
    fclose(f_bubble);

    char stats_filename[50] = "characteristics_";
    strcat(stats_filename, formattedTime);
    strcat(stats_filename, ".txt");
    FILE *f_stats = fopen(stats_filename, "w");
    fprintf(f_stats, "Quick Sort: %d\t%d\t%d\n", quickSortStats.comparisons, quickSortStats.swaps, quick_time);
    fprintf(f_stats, "Shaker Sort: %d\t%d\t%d\n", shakerSortStats.comparisons, shakerSortStats.swaps, shaker_time);
    fprintf(f_stats, "Bubble Sort: %d\t%d\t%d\n", bubbleSortStats.comparisons, bubbleSortStats.swaps, bubble_time);
    return 0;
}
