#include "header.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>



#define TAM_STR 50
#define TAM_STR_MAIN 100



typedef struct comando {
	char * comando;
	struct comando * prox;
} * COMANDO;


int wordcount(char * str){
	int status = 0, counter = 0,i;

	for(i=0; str[i] != '\0'; i++){
		if (status == 0 && str[i] != ' '){
			status = 1;
			counter++;
		}
		else if (status == 1 && str[i] == ' '){
			status = 0;
		}
	}

	return counter;
}


int mysystem(const char * command){

   int p = fork();

   if (p == 0) {
	   int n = conta_palavras(command); 				//contar palavras

	   int v[n],i; 										//array com o tam das palavra
	   for(i=0; i < n; v[i++]=0); 						//inicializar o array

	   char ** args = malloc((n+1)*sizeof(char*)); 		//alocar espaço para os argumentos
	   for(i=0; i <= n; i++)
		   args[i] = malloc(TAM_STR*sizeof(char));

	   args[n] = NULL;


	   escreve_conta_palavras(command,v,n,args); 		//preencher os argumentos

	   execvp(args[0],args); 							//executar
	   perror("erros->bla");
	   _exit(0);

   }

   return 0;
}


int main(int argc, char const *argv[]) {

	int p[2];
	int i = 0, n;
	char ** args;
	char buffer;

	if (argc != 2) {
		perror("Numero de argumentos inválido");
		exit(-1);
	}

	int fd = open(argv[1], O_RDWR | O_CREAT, 00644);


	LINHA linhas = parse(fd);



	return 1;
}
