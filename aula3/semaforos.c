#include <stdio.h>
#include <sys/sem.h>

//int semget(key_t key, int nsems, int semflg) //criando um conjunto de semáforos

//key é uma chave númerica que identifica o conjunto do semáforos
//nsems indica o número de semáforos do conjunto
//semflg que indica o modo de ciração do semáforo


//função semclt(int semid, int semnum, int cmd, unionin senum arg) função de controle
//semid: identificação do conjunto de semáforo
//semnum: numero de semáforos

//realiza controle nos semáforos
//a função pode ter 3 ou 4 argumentos
//o quarto argumento deve ser to tipo union senum

int main(){
  int semid, chave;
  chave = ftok("/home/rodrigowfalcao/.mozilla/firefox/profiles.ini", 'b');
  semid = semget(chave, 4, IPC_CREAT | 0600);
  printf("chave = %d\n", chave);
  printf("semid = %d\n", semid);

  return 0;
}
