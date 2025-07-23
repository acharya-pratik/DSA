#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void merge(int A[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int size = r - l + 1;
    int *B = (int *)malloc(size * sizeof(int));

    while (i <= m && j <= r) {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i <= m)
        B[k++] = A[i++];
    while (j <= r)
        B[k++] = A[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        A[i] = B[k];

}

void mergesort(int A[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(A, l, m);
        mergesort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

void display(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[MAX], n, i;
    clock_t start, end;
    double diff;

    printf("Enter the number: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid size\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        A[i] = rand() % 1000;
    }

    printf("Unsorted array:\n");
    display(A, n);

    start = clock();
    mergesort(A, 0, n - 1);
    end = clock();

    printf("Sorted array:\n");
    display(A, n);

    diff = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", diff);

    return 0;
}

