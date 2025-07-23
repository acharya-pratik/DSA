#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int partition(int A[], int l, int r) {
    int pivot = A[l];
    int x = l + 1;
    int y = r;
    int temp;

    while (x <= y) {
        while (x <= r && A[x] <= pivot)
            x++;
        while (y >= l && A[y] > pivot)
            y--;
        if (x < y) {
            temp = A[x];
            A[x] = A[y];
            A[y] = temp;
        }
    }
    // swap pivot into correct position
    A[l] = A[y];
    A[y] = pivot;
    return y;
}

void quicksort(int A[], int l, int r) {
    if (l < r) {
        int p = partition(A, l, r);
        quicksort(A, l, p - 1);
        quicksort(A, p + 1, r);
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
    // display(A, n);

    start = clock();
    quicksort(A, 0, n - 1);
    end = clock();

    // printf("Sorted array:\n");
    // display(A, n);

    diff = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", diff);

    return 0;
}

