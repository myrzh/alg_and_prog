#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else return n * f(n - 1);
}

void permute(int n) {
    if (n == 1) {
        
    }
    for (int i = 0; i < n; i++) {
        swap(&A[n - 1], &A[n - 1 - i]);
        permute(n - 1);
        swap(&A[n - 1], &A[n - 1 - i]);
    }
}

void hanoy(int k, int l, int n) {
    if (n == 1) {
        printf("Ход с %d на %d", k, l);
    } else {
        int t = 6 - k - l;
        hanoy(k, t, n - 1);
        printf("Ход с %d на %d", k, l);
        hanoy(t, l, n - 1);
    }
}

int main() {
    char A[] = {'a', 'b', 'c', 'd'};
    return 0;
}
