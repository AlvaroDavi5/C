run: programafinal
	@ ./programafinal


valgrind: programafinal
	@ valgrind ./programafinal


all: programafinal


programafinal: main.o myfuncs.o
	@ gcc -o programafinal main.o myfuncs.o
	@ echo "Binário criado!"
	@ echo ''


main.o: main.c myfuncs.h
	@ gcc -c main.c -o main.o
	@ echo "main.o gerado"
	@ echo ''

myfuncs.o: myfuncs.c myfuncs.h
	@ gcc -c myfuncs.c -o myfuncs.o
	@ echo "myfuncs.o gerado"
	@ echo ''


clean:
	@ rm -rf *.o *~ programafinal
	@ echo "Tudo limpo!"
	@ echo ''

