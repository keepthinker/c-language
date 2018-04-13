#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#define SIZE 10000

void *count(void *arg);
void *countNotSync(void *arg);
unsigned int cnt;
sem_t sem;

int main()
{
  pthread_t t1, t2;
  
  sem_init(&sem, 0, 1);

  pthread_create(&t1, NULL, count, NULL);
  pthread_create(&t2, NULL, count, NULL);
  
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  
  printf("cnt=%d\n", cnt);
  
  cnt = 0;
  
  pthread_create(&t1, NULL, countNotSync, NULL);
  pthread_create(&t2, NULL, countNotSync, NULL);
  
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("cntNotSync=%d\n", cnt);


  return 0;
}

void *count(void *arg)
{
  int i;
  for(i = 0; i < SIZE; i++)
  {
    sem_wait(&sem);
    cnt++;
    sem_post(&sem);
  }
}

void *countNotSync(void *arg)
{
  int i;
  for(i = 0; i < SIZE; i++)
  {
    cnt++;
  }
}
