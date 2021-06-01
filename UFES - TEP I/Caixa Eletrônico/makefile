
BIN_NAME=programafinal


C_SOURCE=$(wildcard ./*.c)

H_SOURCE=$(wildcard ./*.h)


OBJ=$(subst .c,.o,$(C_SOURCE))


CPL=gcc

CPL_FLAGS=-c   \
          -lm  \
          -W   \
          -Wall


VALGRIND_FLAGS=--leak-check=full \
               --show-leak-kinds=all \
               --track-origins=yes \
               --verbose


all: ${BIN_NAME} folders
	@ echo " \033[1;32m  Tudo feito!  \033[0m "
	@ echo ''


valgrind: all
	@ echo ''
	@ valgrind ${VALGRIND_FLAGS} ./${BIN_NAME}
	@ echo ''


${BIN_NAME}: ${OBJ}
	@ ${CPL} $^ -o $@
	@ echo " \033[0;33m  Criando binario \033[43;1;37m$@\033[0m\033[0;33m  \033[0m "
	@ echo ''


folders:
	@ mkdir -p "./output"


./%.o: ./%.c ./%.h
	@ ${CPL} $< ${CPL_FLAGS} -o $@
	@ echo " \033[0;35m  Gerando objeto de compilacao \033[45;1;37m$@\033[0m\033[0;35m  \033[0m "
	@ echo ''


./main.o: ./main.c ${H_SOURCE}
	@ ${CPL} $< ${CPL_FLAGS} -o $@
	@ echo " \033[0;34m  Gerando objeto de compilacao \033[44;1;37m$@\033[0m\033[0;34m  \033[0m "
	@ echo ''


clean:
	@ rm -rf ./output ./*.o *~ ${BIN_NAME}
	@ echo " \033[1;31m  Removendo binario \033[41;1;37m${BIN_NAME}\033[0m\033[1;31m e objetos de compilacao \033[41;1;37m${OBJ}\033[0m\033[1;31m e arquivos de output e arquivos de backup \033[0m "
	@ echo ''
