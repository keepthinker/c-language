#include<unistd.h>
#include<stdio.h>
int main()
{
  printf("start to sleep");
  int a = sleep(10);
  printf("result is %d\n", a);
  return 0;
}
