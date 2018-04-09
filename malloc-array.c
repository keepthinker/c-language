#include<stdio.h>
#include<stdlib.h>

int main()
{
  long sizeint = sizeof(int);
  printf("size of int: %ld\n", sizeint);

  int *arr, n;
  printf("size of array: ");
  scanf("%d", &n);
  
  arr = (int *)malloc(sizeint * 8);
  int i;
  for(i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  
  for(i = 0; i < n; i++)
  {
    printf("%d ", *(arr + i));
  }
  
  free(arr);
  return 0;

}
