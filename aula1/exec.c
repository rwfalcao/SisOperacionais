#include <stdio.h>
#include <unistd.h>

void main(){
	execl("/bin/lsx", "ls", "-l", NULL);
	printf("Vao imprimir ou não?");
}
