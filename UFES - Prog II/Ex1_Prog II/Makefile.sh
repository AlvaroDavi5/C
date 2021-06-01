 #!/bin/bash

TOTAL=$(ls *.c | wc -l) # Listar quantidade de arquivos com extensão .c

 for (( i = 1; i <= ${TOTAL}; i++ )); do

 	echo "Compilando ex${i}"
	gcc ex${i}.c -o ex${i} -lm
 	echo "Pronto!"
 	echo ''

 done
