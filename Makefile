.PHONY: Thread, Process

MyExample: 
	gcc -lpthread Example.c && ./a.out
	
Thread:
	gcc -o Thread -pthread Thread.c 
	./Thread
	
Process:
	gcc -o Process Process.c 
	./Process

clean: 
	rm -f *.out
	
clean2:
	rm a.exe
	
