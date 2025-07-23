

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000
void insertation(int A[],int n)
{
  int pos;
 for (int i=0; i<n; i++) {
 int temp = A[i];
    int j= i-1;
    while(j>=0 && temp<A[j]){
    A[j+1]=A[j];
      j=j-1;

    }
    A[j+1]=temp;
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
  insertation(A,n);
  end = clock();
  diff=end-start;
  display(A,n);
  printf("time: %f",diff);
  return 0 ;
}
