#include <stdio.h>
#include <string.h>

char *edit_line(char line1[], char line2[]) {
    char line3[strlen(line1) * 2 + 1];
    int line3_index = 0;
    int is_present = 0;
    for (int i = 0; i < strlen(line1); i++) {
        if ((int)(line1[i]) >= 97) {
            is_present = 0;
            for (int j = 0; j <= strlen(line2); j++) {
                if (line1[i] == line2[j]) {
                    is_present = 1;
                }
            }
            if (is_present) {
                line3[line3_index] = line1[i];
                line3_index++;
                line3[line3_index] = line1[i];
                line3_index++;
            }
        } else {
            is_present = 0;
            for (int j = 0; j <= strlen(line2); j++) {
                if (line1[i] == line2[j]) {
                    is_present = 1;
                }
            }
            if (!is_present) {
                line3[line3_index] = line1[i];
                line3_index++;
            }
        }
    }
    return line3;
}

int main() {
    char line1_example[] = "aBBa";
    char line2_example[] = "aB";
    char line3_example[100];
    strcpy(line3_example, edit_line(line1_example, line2_example));
    printf("%s\n", line3_example);
}
