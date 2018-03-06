#include <stdio.h>
#include <pthread.h>

void Tarefa(int *id){
	long tid;
	printf("\nOla esta é a thread executado com parâmetro %d\n", *id);
	pthread_exit(NULL);
}

void Tarefa2(int *a){
	int i=*a;
	printf("\n***Ola, eu sou a thread = %d\n", i);

}

int somaMatrizes(int matrix1[4][4], int matrix2[4][4], int** matrix_result){
	int i,j;
	
	for(i = 0 ; i < 4 ; i++){
		for(j = 0 ; j < 4 ; j++){
			matrix_result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
		
}

void printMatrix(int** matrix){
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			printf("%d", matrix[i][j]);
		}
		printf("\n");	
	}	
}

int soma(int a, int b){
	return a+b; 
}


int initializeMatrix(int** matrix){
	int i = 0;
	int j = 0;
	for(i = 0 ; i < 4 ; i++){
		for(j = 0 ; j < 4 ; j++){
			matrix[i][j] = j+i;
		}		
	}	
}
int main(){

	pthread_t thread2[4];
	int y,t[4],t2, x=10;
/*
	t = pthread_create(&thread1, NULL, (void*) Tarefa2, &y);
*/		
	for(y=0 ; y<4 ; y++){
		t[y] = y;
		printf ("\nantes y=%d\n",y);
		t2 = pthread_create(&thread2[y], NULL, (void*) Tarefa2, &t[y]);
		printf ("\ndepois y=%d\n",y);
	} 

	pthread_exit(NULL);

	int matrix1[4][4], matrix2[4][4],matrix3[4][4], i, j;
	initializeMatrix(matrix1);
	initializeMatrix(matrix2);
	
	
	
	
	
	
}
