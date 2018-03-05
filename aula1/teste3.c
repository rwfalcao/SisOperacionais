#include <stdio.h>
#include <unistd.h> //incluimos por conta da função fork e do tipo de dado que precisamos

void main(){

        pid_t pid; //tipo para criar um processo é o pid_t
        pid = fork(); //a função fork atribuida à um processo cria um processo além do processo principal que é o próprio programa

	int i,j;

//      printf("\nprocesso de fora: %d\n",getpid());

        if (pid == 0){ //se o pid for igual à zero quer dizer que ele é processo filho
                for(i=0;i<5;i++){
			printf("sou um filho: %d\n\n",getpid()); //getpid() retorna o código do processo em questão.
       			sleep(3);
		}
	 }else{
		wait(); //wait() o pai espera o filho terminar de executar
		for(i=0;i<3;i++){
                	printf("sou um pai: %d\n\n",getpid());
       			//wait(0); //wait() o pai espera o filho terminar de executar
		}
	 }
}

