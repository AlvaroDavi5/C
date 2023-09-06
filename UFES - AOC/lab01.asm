.data
	msg1: .asciiz "Digite um valor inteiro: "	# define a string variable named msg1

.text
	# the following lines are used to print msg1 on shell
	main: li $v0, 4 			# system call for print_str msg
	la $a0, msg1 		# address of string to print
	syscall			# assembly instruction to call a system message (print_str in this case)

	# now get an integer from the user using a system call (syscall)
	li $v0, 5 			# system call for read_int msg, and the integer read is placed in $v0
	syscall 			# assembly instruction to call a system message (read_int in this case)

	# do some computation here with the number
	addu $t0, $v0, $zero 	# move the number to $t0 ($t0 = $v0 + $zero, unsigned)
	sll $t0, $t0, 6 	# change <digit> with the last digit of your UFES id (matricula) 



	# print the result in shell
	li $v0, 1 			# system call for print_int msg (intialization)
	addu $a0, $t0, $0 	# the number to be printed must be in $a0 register
	syscall			# assembly instruction to call a system message (print_int in this case)

	# goto main
	j main 			# return to the main label
