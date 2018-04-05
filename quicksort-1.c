#include<stdio.h>
#include<stdlib.h>
void printArr(int arr[], int len);
void quicksort(int arr[], int start, int end);

int main()
{
  int arr[] = {31, 232, 2, 8, 8, 10, 9, 823, 23};

  quicksort(arr, 0, 9);
  printArr(arr, 9);
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
  int pivot = arr[start];
  int i = start;
  int j = end;
  while(i < j)
  {
    while(arr[j] >= pivot && i < j)
      j--;
    arr[i] = arr[j];
    while(arr[i] <= pivot && i < j)
      i++;
    arr[j] = arr[i];
  }
  arr[j] = pivot;
  quicksort(arr, start, i);
  quicksort(arr, i+1, end);
}
