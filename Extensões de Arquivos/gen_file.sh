 #!/bin/bash

echo "Gerando arquivos..."
gcc -E hello_world.c -o hello_world.i
gcc -S hello_world.i -o hello_world.s
cp ./hello_world.s ./hello_world.asm
gcc -c hello_world.s -o hello_world.o
gcc hello_world.o -o hello_world
gcc hello_world.c -o hello_world.out
gcc hello_world.c -o hello_world.exe
gcc hello_world.c -o hello_world
echo 'Pronto!'
echo ''

