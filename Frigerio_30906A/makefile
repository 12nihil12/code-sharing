bersaglio.o: bersaglio.C bersaglio.h 
	g++ bersaglio.C -c 

colpi.o: colpi.C colpi.h
	g++ colpi.C -c 

main.o: main.C 
	g++ main.C -c 

main.x: main.o bersaglio.o colpi.o
	g++ main.o bersaglio.o colpi.o -o main.x 

compila:main.x 

esegui: main.x
	./main.x 

