#include <stdio.h>
 
int binary_add(int A[], int B[], int n){
  int sum[n+1];
  int i;
  int carry = 0;
  for(i = n-1; i >= 0; i--){
    sum[i+1] = (A[i] + B[i] + carry) % 2;
    carry = (A[i] + B[i] + carry) / 2;
  }
  sum[0] = carry;
  for(i = 0; i < n+1; i++){
    printf("%d ", sum[i]);
  }
}
 
int main(){
  int n;
  scanf("%d", &n);
  int i, j;
  int A[n];
  for(i = 0; i < n; i++){
    scanf("%d ", &A[i]);
  }
  int B[n];
  for(j = 0; j < n; j++){
    scanf("%d ", &B[j]);
  }
  binary_add(A, B, n);
  return 0;
}