#include <stdio.h>

struct Values {
	int val1;
    int val2;
};


int abs(int arg) {
	if (arg >= 0)
    {
    	return arg;
    } else {
    	return -arg;
    }
}

struct Values find_indexes(int A[], int B[], int n, int x) {
	int best_i = 0;
    int best_j = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n, j++) {
            int delta = abs(A[i] + B[j] - x);
            if (delta <= abs(A[best_i] + B[best_j] - x)) {
            	best_i = i;
                best_j = j;
            }
        }
    }
    struct Values result;
  	result.val1 = best_i;
    result.val2 = best_j;
    return result;
}

int main()
{	
	const int N = 5;
	int A[N] = {4, 3, 6, 3, 9};
    int B[N] = {23, 5, 21, 54, 34};
    int x = 64;
    struct Values result = find_indexes(A, B, N, x);
    printf("%d %d", result.val1, result.val2);
    return 0;
}
