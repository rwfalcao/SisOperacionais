#include <stdio.h>
#include <unistd.h> //incluimos por conta da função fork e do tipo de dado que precisamos

void main(){
	
	pid_t pid; //tipo para criar um processo é o pid_t
	pid = fork(); //a função fork atribuida à um processo cria um processo além do processo principal que é o próprio programa
	
//	printf("\nprocesso de fora: %d\n",getpid());
	
	if (pid == 0){ //se o pid for igual à zero quer dizer que ele é processo filho
		printf("sou um filho: %d\n\n Meu pai é %d",getpid(),getppid()); //getpid() retorna o código do processo em questão.
	}else{
		printf("sou um pai: %d\n\n O avô do filho é %d\n\n",getpid(),getppid());
	}
}

//quando a função fork é chamada nós temos uma cópia exata e identica é colocada em outra área de memória.

//então temos dois processos idênticos, o processo filho utiliza o mesmo código do pai e dos recursos do pai até o momento da criação do filho, como por exemplo arquivos que estavam abertos pelo pai.

//No unix o filho é hierarquicamente dependente do pai, ou seja, se o pai morre o filho morre também.

//primeiro processo a se iniciar no unix é o 'init'


