#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000
void bubblesort(int A[],int n)
{
  int i,j,temp;
  for (i=0; i<n-1; i++) {
    for (j=0; j<n-i-1;j++) {
      if(A[j]>A[j+1])
      {
        temp = A[j];
        A[j]=A[j+1];
        A[j+1]=A[j];
      }

    }

  }
}
void display(int A[],int n){
  int i;
  for (i=0; i<n; i++) {
    printf("%d ",A[i]);

  }
  printf("\n");

}
int main(){
  int A[MAX],n,i;
  time_t start,end;
  double diff;
  printf("Enter the number:");
  scanf("%d",&n);
  for (i=0;i<n;i++){
    A[i]=rand()%1000;
  }
  display(A,n);
  start = clock();
  bubblesort(A,n);
  end = clock();
  diff = (double)(end - start) / CLOCKS_PER_SEC;
  display(A,n);
  printf("time: %f",diff);
  return 0 ;
}
