#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

sem_t mutex;
int cont; /*variável compartilhada*/

void tarefa(void *ptr){
  int x;
  x = *((int *) ptr);
  printf("Thread %d: Aguardando para entrar na região crítica...\n",x);
  sem_wait(&mutex); /*Aciona o semáforo*/
  /*Entra na região crítia*/
  printf("Thread %d: está na região crítica\n",x);
  printf("Thread %d: valor do contador %d\n", x, cont);
  printf("Thread %d: Incrementando o contador",x);
  cont++;
  printf("Thread %d: novo valor do ocntador: %d\n",x, cont);
  printf("Thread %d: Deixando a região crítica\n",x);
  /*Fim da região crítica*/
  sem_post(&mutex); /*liberando o semáforo*/

  pthread_exit(0); /*Finaliza a thread*/

}

int main(){
  int i[2];
  pthread_t thread1, thread2;
  i[0] = 0; /*valores para as threads*/
  i[1] = 1;

  sem_init(&mutex,0,1); /* inicialize o semáfooro binário mutex como 1 */
  /* o segundo parâmetro = 0 - indica que o semáforo é local */

  pthread_create(&thread1, NULL, (void *) &tarefa, (void *) &i[0]);
  pthread_create(&thread2, NULL, (void *) &tarefa, (void *) &i[1]);

  pthread_join(thread1, NULL);
  pthread_join(thread1, NULL);

  sem_destroy(&mutex); /* finaliza o semáforo */
  exit(0);
}
