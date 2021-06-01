# SOBRE


.c  
**codigo-fonte em linguagem C**  

.h  
**arquivo de cabecalho (header) da linguagem C**  

.i  
**arquivo de output do pre-processamento**  

.s .asm  
**codigo-fonte em linguagem Assembly**  

.o  
**arquivo de objeto compilado**  

.out .bin .exe  
**arquivo de output da compilacao para linguagem de maquina (binario)**  

.sh  
**arquivo de Shell Script**  

makefile  
**arquivo de instrucoes para gerar binario**  




	gcc -E hello_word.c -o hello_word.i  
	gcc -S hello_word.i -o hello_word.s  
	gcc -c hello_word.s -o hello_word.o  
	gcc hello_word.o -o hello_word  
	gcc hello_word.c -o hello_word.out 
	gcc hello_word.c -o hello_word.exe 
	gcc hello_word.c -o hello_word  

