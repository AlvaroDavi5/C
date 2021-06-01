 #!/bin/bash

echo "Gerando arquivos..."
gcc -E hello_word.c -o hello_word.i
gcc -S hello_word.i -o hello_word.s
gcc -c hello_word.s -o hello_word.o
gcc hello_word.o -o hello_word
gcc hello_word.c -o hello_word.out
gcc hello_word.c -o hello_word.exe
gcc hello_word.c -o hello_word
echo 'Pronto!'
echo ''

