#include<stdio.h>
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
  int j = start + 1;
  while(j < end)
  {
    if(arr[j] < pivot)
    { 
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
    }
    j++;
  }
  arr[i] = pivot;
  quicksort(arr, start, i);
  quicksort(arr, i + 1, end);
}
