
# variavel 'BIN_NAME' recebe o nome do programa em arquivo binario
BIN_NAME=complex_program


# macro 'C_SOURCE' usa funcao wildcard para obter os nomes de todos os arquivos de codigo-fonte com extensao .c
C_SOURCE=$(wildcard ./source/*.c)

# macro 'H_SOURCE' usa funcao wildcard para obter os nomes de todos os arquivos de codigo-fonte com extensao .h
H_SOURCE=$(wildcard ./include/*.h)


# macro 'OBJ' utiliza todos os nomes dos arquivos de 'C_SOURCE', entretanto substitui .c por .o e 'source' por 'objects'
OBJ=$(subst .c,.o,$(subst source,objects,$(C_SOURCE)))
#OBJ=${C_SOURCE:.c=.o}


# definindo compilador e flags
CPL=gcc

CPL_FLAGS=-c   \
          -lm  \
          -W   \
          -Wall
# usado Space no lugar de Tab para evitar erros


# o target 'all' tem como pre-requisito a variavel 'BIN_NAME' e a variavel 'objectFolder', que se tornam targets
all: objectFolder ${BIN_NAME}
	@ echo " \033[1;32m  Tudo feito!  \033[0m "
	@ echo ''
# ${} e $() podem igualmente ser usadas para macros


# target para criar diretorio dos objetos de compilacao
objectFolder:
	@ mkdir -p objects
# @ oculta linha


# o target 'BIN_NAME' tem como pre-requisito a macro 'OBJ' e seus arquivos
${BIN_NAME}: ${OBJ}
	${CPL} $^ -o $@
	@ echo " \033[0;33m  Criando binario \033[43;1;37m$@\033[0m\033[0;33m  \033[0m "
	@ echo ''
# $@ nome do target, $^ todos os pre-requisitos, $< primeiro pre-equisito


# o target '%.o' pega o stem (tronco do nome, sem extensao) e o utiliza como referencia no pre-requisito
./objects/%.o: ./source/%.c ./include/%.h
	${CPL} $< ${CPL_FLAGS} -o $@
	@ echo " \033[0;35m  Gerando objeto de compilacao \033[45;1;37m$@\033[0m\033[0;35m  \033[0m "
	@ echo ''


# main e compilado aqui pois nao atende os pre-requisitos para o target anterior
./objects/main.o: ./source/main.c ${H_SOURCE}
	${CPL} $< ${CPL_FLAGS} -o $@
	@ echo " \033[0;34m  Gerando objeto de compilacao \033[44;1;37m$@\033[0m\033[0;34m  \033[0m "
	@ echo ''


# o target 'clean' nao tem como pre-requisito, serve para remover arquivos residuais
clean:
	rm -rf ./objects/*.o *~ ${BIN_NAME}
	rmdir objects
	@ echo " \033[1;31m  Removendo binario \033[41;1;37m${BIN_NAME}\033[0m\033[1;31m e objetos de compilacao \033[41;1;37m${OBJ}\033[0m\033[1;31m e arquivos de backup  \033[0m "
	@ echo ''
