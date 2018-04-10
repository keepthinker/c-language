#include<stdio.h>
#include<stdlib.h>
#define N 2
char **ptr;

void *thread(void *vargp);

int main()
{
  int i;
  pthread_t tid;
  char *msgs[N] = {"Hello from foo", "Hello from bar"};
  ptr = msgs;
  
  for(i = 0; i < N; i++)
  {
    int* t = (int *)malloc(sizeof(int));
    *t = i;
    pthread_create(&tid, NULL, thread, t);
  }
  pthread_exit(NULL);

}

void *thread(void *vargp)
{
  int myid = *(int *)vargp;
  static int cnt = 0;

  printf("[%d]: %s (cnt=%d)\n", myid, ptr[myid], ++cnt);
  free(vargp);
}
