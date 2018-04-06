#include<stdio.h>
#include<stdlib.h>
void printArr(int arr[], int len);
void mergesort(int arr[], int start, int end);

int main()
{
  int arr[] = {31, 232, 2, 8, 8, 10, 9, 823, 23, 2, 1, 2};
  printf("origin array: ");
  printArr(arr, 12);
  mergesort(arr, 0, 11);
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

void mergesort(int arr[], int low, int high)
{ 
  if(low >= high)
    return;
  int mid = (high - low) / 2 + low;
  mergesort(arr, low, mid);
  mergesort(arr, mid + 1, high);
 
  int tempSize = high - low + 1; 
  int tempArr[tempSize];
  int a = 0;
  int b;
  for(b = low; b <= high; b++)
    tempArr[a++] = arr[b]; 
  int tempi = 0;
  int tempmid = mid - low;
  int tempj = tempmid + 1;
  int temph = high - low;
  int i = low;
  while(tempi <= tempmid && tempj <= temph)
  {
    if(tempArr[tempi] < tempArr[tempj])
    {
      arr[i++] = tempArr[tempi];
      tempi++;
    } else {
      arr[i++] = tempArr[tempj];
      tempj++;
    }
  }
  if(tempi <= tempmid)
  {
    for(; tempi <= tempmid; tempi++)
      arr[i++] = tempArr[tempi];
  }
  if(tempj <= temph)
  {
    for(; tempj <= temph; tempj++)
      arr[i++] = tempArr[tempj];
  }
}
