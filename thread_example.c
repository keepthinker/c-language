#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *thread(void *var);
void *cancelThread(void *var);
int main()
{

  pthread_t tid;
  int s1 = 2; 
  pthread_create(&tid, NULL, thread, &s1);
  printf("thread id: %ld\n", tid);

  pthread_t tid2;
  int s2 = 3;
  pthread_create(&tid2, NULL, cancelThread, &tid);
  pthread_join(tid, NULL);
  printf("finish\n");
  return 0;
}

void *thread(void *var)
{
  printf("thread id: %ld, sleep for %d second\n", pthread_self(), *(int *)var);
  sleep(*(int *)var);
  printf("sleep end");
}

void *cancelThread(void *var)
{ 
  printf("wait 1s to cancel thread: %ld\n", *(pthread_t *)var);
  sleep(1);
  pthread_cancel(*(pthread_t*)var);
}
