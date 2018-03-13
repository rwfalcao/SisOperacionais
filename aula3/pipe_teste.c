#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
	int i, desc1[2], desc2[2];
	pid_t pid;
	char texto[100], buffer[] = "Teste de comunicação com pipes";
	char text2[100], buffer2[] = "Outro texto para teste de comunicação";

	pipe(desc1); /*O pipe é criado antes do filho para que pai e filho tenham o mesmo descritor, o que permitirá a comunicação*/
	pipe(desc2);

	pid = fork();

	if(pid == 0){
		/*Operações do desc1*/
		close(desc1[1]); /*fecha o pipe para escrita, pois o filho só vai ler*/
		read(desc1[0], texto, sizeof(texto)+1); /*lê a mensagem no pipe*/

		printf("\n\nA mensagem lida pelo filho foi: \n'%s'",texto);
		close(desc1[0]);
		
		/*Operações do desc2*/
		close(desc2[0]);
		for(i = 0 ; i < 20000 ; i++){
			write(desc2[1], buffer2, sizeof(buffer2)+1);
		}
		close(desc2[1]);
	}
	else{
		/*Operações do desc1*/
		close(desc1[0]); /*fecha o pipe para leitura, pois o pai só vai escrever*/
		write(desc1[1], buffer, sizeof(buffer)+1); /* escreve no buffer */
		wait(0);
		/*Operações do desc2*/
		close(desc2[1]);
		read(desc2[0], text2, sizeof(text2)+1);
			
		printf("\n\nO pai leu a seguinte mensagem do filho:\n '%s'", text2);	
		
		printf("\n\nAcabou minha espera\n");
	}

	return 0;
}
