
# o target 'all' tem como pre-requisito o arquivo binario 'printy', que se torna um target
all: printy


# target 'run' feito para executar o programa
run: printy
	@ ./printy


# target 'valgrind' feito para verificar vazamentos de memoria no programa
valgrind: printy
	@ valgrind ./printy


# o target 'printy' tem como pre-requisito os arquivos 'main.o' e 'helloWorld.o'
printy: main.o helloWorld.o
	gcc -o printy main.o helloWorld.o
	@ echo ''


# os targets dos arquivos .o tem como pre-requisito os arquivos .c
main.o: main.c helloWorld.h
	gcc -c main.c -o main.o
	#gcc -o main.o main.c -c -W -Wall -ansi -pedantic
	@ echo ''

helloWorld.o: helloWorld.c helloWorld.h
	gcc -c helloWorld.c -o helloWorld.o
	#gcc -o helloWorld.o helloWorld.c -c -W -Wall -ansi -pedantic
	@ echo ''


# o target 'clean' nao tem como pre-requisito, serve para remover arquivos residuais
clean:
	rm -rf *.o *~ printy # removendo diretorios e arquivos .o, arquivos de backup e versao antiga do 'printy'
	@ echo ''
