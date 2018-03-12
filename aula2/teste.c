#include <stdio.h>
#include <pthread.h>

void Tarefa(int *id){
  printf("\nOlá, esta é a thread executando com parâmetro %d\n", *id);
  pthread_exit(NULL);
}

int main(){
  pthread_t thread1;
  int t, x=10;

  t = pthread_create(&thread1, NULL, (void*) Tarefa, &x);

  pthread_exit(NULL);
}
