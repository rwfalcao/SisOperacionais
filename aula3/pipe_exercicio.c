#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
	int descritor[2];
	pid_t pid;
	char texto[100], buffer[] = "Teste de comunicação com pipes";

	pipe(descritor); /*O pipe é criado antes do filho para que pai e filho tenham o mesmo descritor, o que permitirá a comunicação*/

	pid = fork();

	if(pid == 0){
		close(descritor[1]); /*fecha o pipe para escrita, pois o filho só vai ler*/
		read(descritor[0], texto, sizeof(texto)+1); /*lê a mensagem no pipe*/

		printf("\n\nA mensagem lida pelo filho foi: \n'%s'",texto);
		close(descritor[0]);
	}
	else{
		close(descritor[0]); /*fecha o pipe para leitura, pois o pai só vai escrever*/
		write(descritor[1], buffer, sizeof(buffer)+1); /* escreve no buffer */
		wait(0);
		printf("\n\nAcabou minha espera\n");
	}

	return 0;
}
