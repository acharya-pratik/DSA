
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000
void selection(int A[],int n)
{
  int pos,least,i,j,temp;
 for (i=0; i<n; i++) {
    least = A[i];
    pos =1;
    for (j=i+1; j<n; j++) {
    if (A[j]<least){
        least = A[j];
        pos =j;
    }
      if(i!=pos)
      {
        temp = A[i];
        A[i]=A[pos];
        A[pos]=temp;
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
  selection(A,n);
  end = clock();
  diff=end-start;
  display(A,n);
  printf("time: %f",diff);
  return 0 ;
}
