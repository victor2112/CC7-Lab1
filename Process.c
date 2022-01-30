#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include <Windows.h>
#include <conio.h>

int g = 0;

// C Concepts 
// https://gist.github.com/Integralist/6c35d4f26c0c7bf5bdce7b95cfa906b3
int main ( int argc , char * argv []) {
	char* tmp = (char*)malloc(10 * sizeof(char));
	printf("Ingrese Numero de Primos: ");
	scanf("%s", tmp);
	//printf("%s\n", tmp);
	g = atoi(tmp);
	free(tmp);

	// New Process
	// https://www.geeksforgeeks.org/fork-system-call/
	pid_t pid ;
	//printf("v Before Process\n"); 
	pid = fork();
	if ( pid == -1) {
		printf ("# Creation of a child process was unsuccessful.\n");
		return -1;
	} else {
		if( pid > 0){
			// Returned to parent or caller. The value contains process ID of newly created child process.
			printf ("PID %d Process Dad\n" , getpid () ) ;
		} else {
			// Returned to the newly created child process
			printf ("PID %d\tProcess Son\n" , getpid () );
		}
	}
	//printf("^  After Process\n"); 
	return 0;
}