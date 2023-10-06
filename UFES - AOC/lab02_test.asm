
.data # data segment

	primeiro: .byte 'A'
	var1: .word 1111
	var2: .word 2222
	var3: .word 3333
	var4: .word 4444
	ultimo: .byte 'S'


.text # instructions segment

	# addresses
	la $t1, var1 # $t1 = &(var1)
	la $t2, var2 # $t2 = &(var2)
	la $t3, var3 # $t3 = &(var3)
	la $t4, var4 # $t4 = &(var4)
	# values
	lw $t5, var1 # $t1 = var1
	lw $t6, var2 # $t6 = var2
	lw $t7, var3 # $t3 = var3
	lw $t8, var4 # $t4 = var4

	# value swap
	add $t0, $t8, $zero # $t0 = $t8 + $zero
	sw $t0, 0($t1) # MEM[$t1] = $t0

	add $t0, $t7, $zero # $t0 = $t7 + $zero
	sw $t0, 0($t2) # MEM[$t2] = $t0

	add $t0, $t6, $zero # $t0 = $t6 + $zero
	sw $t0, 0($t3) # MEM[$t3] = $t0

	add $t0, $t5, $zero # $t0 = $t5 + $zero
	sw $t0, 0($t4) # MEM[$t4] = $t0

	# exit
	li $v0, 10 # load immediate syscall to exit (10)
	syscall # system call
