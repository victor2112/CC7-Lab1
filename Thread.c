#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 

int g = 0;

void *myThread(void *vargp) {
	int *myid = (int *)vargp; 
	
	int valores=2;
	int primo=0;
	int divisores=0;

    for(int i=1; i <= g; i=i)
	{
		primo=0;
		// Calcular divisores del numero
		for(divisores=2;divisores<=valores-1 && primo==0;divisores++)
			{
			// Comprobar si existe un divisor
			if(valores%divisores==0) primo=1;
			}
		// Si no se ha encontrado ningun divisor el valor de primo no
		// ha cambiado y por tanto el numero del bucle principal examinado
		// es un valor primo
	   	if(primo==0) 
		   	{
			printf("Thread %d: ", *myid);
			printf("El Numero %d es Primo.\n",valores);
			i++;
			sleep(1);
			}
		valores++;
	}
	
	return NULL; 
} 

// C Concepts 
// https://gist.github.com/Integralist/6c35d4f26c0c7bf5bdce7b95cfa906b3
int main ( int argc , char *argv[]) {
	char* tmp = (char*)malloc(10 * sizeof(char));
	printf("Ingrese Numero de Primos: ");
	scanf("%s", tmp);
	//printf("%s\n", tmp);
	g = atoi(tmp);
	free(tmp);
	
	
	// Multithreading
	// https://www.geeksforgeeks.org/multithreading-c-2/
	pthread_t tid; 
	pthread_t tid2;
	
	//printf("v Before Thread\n"); 
	pthread_create(&tid, NULL, myThread, (void *)&tid ); 
	pthread_create(&tid2, NULL, myThread, (void *)&tid2 ); 
	
	pthread_join(tid, NULL); 
	pthread_join(tid2, NULL);
	//printf("^  After Thread\n"); 
	
	printf("Fin.\n");
	
	pthread_exit(NULL);
	
	return 0;
}
