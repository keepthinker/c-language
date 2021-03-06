#include<stdio.h>
void printArr(int arr[], int len);
void quicksort(int arr[], int start, int end);

int main()
{
  int arr[] = {31, 232, 2, 8, 8, 10, 9, 823, 23, 1, 1, 2};
  printf("origin arr: ");
  printArr(arr, 12);
  quicksort(arr, 0, 12);
  printArr(arr, 12);
  return 0;
}

void printArr(int arr[], int len)
{
  int i;
  for(i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void quicksort(int arr[], int start, int end)
{
  if(start >= end)
  {
    return;
  }
  int pivot = arr[end - 1];
  int i = start;
  int j, len;
  for(j = start, len = end -1; j < len; j++)
  {
    if(arr[j] < pivot)
    { 
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
    }
  }
  arr[end - 1] = arr[i];
  arr[i] = pivot;
  
  quicksort(arr, start, i);
  quicksort(arr, i + 1, end);
}
