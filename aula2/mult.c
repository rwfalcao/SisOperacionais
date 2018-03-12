#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define R 100
#define C 100


int m1 = [R][C];
int m2 = [R][C];
int M = [R][C];

struct v{
  int i;  /* Linha */
  int j;  /* Coluna */
}

void *thread_work(void *param); /* protótipo */

int main(){
  int i, j;
  for(i = 0 ; i < R ; i++){
    for (j = 0 ; j < C ; j++){

      struct v *data = (struct v *) malloc(sizeof(struct v));
      data->i = i;
      data->j = j;

      pthread_t tid;

      pthread_create($tid, NULL, thread_work, data);
      pthread_join(tid, NULL);
    }
  }

  for(i = 0; i < M; i++) {
     for(j = 0; j < N; j++) {
        printf("%d ", C[i][j]);
     }
     printf("\n");
  }

}

void *thread_work(void *param){
  struct v *data = param;
  int n, sum = 0;

  for(n = 0 ; n < R ; n++){
    sum += A[data->i][data->j] = sum;
  }

  M[data->i][data->] = sum;
}
