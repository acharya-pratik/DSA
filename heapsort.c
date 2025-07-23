
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void max_meapify(int A[],int i, int n)
{
  int temp;
  int l=2*i;
  int r=2*i+1;
  int largest = i;
  if(l<=n && A[l]>A[largest])
    largest=l;
  if(r<=n && A[r]>A[largest])
    largest = r;
  if(i!=largest){
    temp =A[i];
    A[i]=A[largest];
    A[largest]=A[i];

    max_meapify(A, largest, n);
  }
}

void build_maxHeap(int A[], int n)
{
  int i;
for (i=n/2; i>=1; i--) {
max_meapify(A, i, n);
}
}

void heapsort(int A[],int n)
{
  int i,temp;
  build_maxHeap(A, n);
  for (i=n; i>=2; i--) {
    temp = A[i];
    A[i]=A[1];
    A[1]=temp;
    max_meapify(A, 1, n);

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
     heapsort(A,n - 1);
    end = clock();

    printf("Sorted array:\n");
    display(A, n);

    diff = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", diff);

    return 0;
}

