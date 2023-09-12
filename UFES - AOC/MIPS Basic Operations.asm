# MIPS 32
  # $zero - zero constant register
  # $v0, $v1 - function returns registers
  # $a0, ..., $a3 - function arguments registers
  # $ra - return address previously the function register
  # $s0, ..., $s8 - storage registers
  # $t0, ..., $t9 - temporary registers


.data # data segment

	msg: .asciiz "Hello World!"
	linebreak: .byte '\n'
	date: .word 1984
	pi: .float 3.14
	read_int_msg: .asciiz "Type a correct result value (int): "
	done_msg: .asciiz "DONE!"
	var1: .word 5555


.text # instructions segment

	# ARITHMETIC OPERATIONS
	li $t0, 5 # load value '5' on $t0 register
	li $t1, 13
	add $s0, $t0, $t1 # store add result on $s0 register, $s0 = $t0 + $t1
	la $t2, ($s0)
	subi $s0, $s0, 3 # $s0 -= 3
	li $t4, 2
	la $t3, ($s0)
	mul $t5, $t3, $t4 # $t5 = $t3 * $t4
	li $t6, 7
	div $t7, $t5, $t6 # $t7 = $t5 / $t6
	mflo $s1 # move from low-order (integer part from the division)
	mfhi $s2 # move from high-order (rest of the division)
	sll $t8, $t5, 1 # $t8 = $t5 * 2^1, $t8 = $t5 << 1
	move $s0, $t8 # $t8 → $s0

	# MEMORY LOAD/STORE OPERATIONS
	la $t8, var1 # $t8 = var1.addr
	lw $t9, var1 # $t9 = var1.word
	sw $s0, 0($t8) # MEM[$t8] = $s0
	sw $t9, 4($t8) # MEM[$t8+4] = $t9

	# SYSTEM CALLS OPERATIONS
	# print string
	li $v0, 4 # load immediate syscall to print_string (4) on '$v0' register
	la $a0, msg # load address
	syscall
	li $v0, 4
	la $a0, linebreak
	syscall
	# print integer
	li $v0, 1 # load immediate syscall to print_int (1)
	lw $a0, date # load world
	syscall
	li $v0, 4
	la $a0, linebreak
	syscall
	# print float
	li $v0, 2 # load immediate syscall to print_float (2)
	lwc1 $f12, pi # load word into coprocessor 1
	syscall
	li $v0, 4
	la $a0, linebreak
	syscall

	read_input: li $v0, 4
	la $a0, read_int_msg
	syscall
	# read integer
	li $v0, 5 # load immediate syscall to read_int (5) and save on '$v0' register
	syscall
	add $s3, $v0, $zero

	# CONDITION FLUX OPERATIONS
	bne $s3, $s0, s3_not_equal_s0 # flux changed by label 's0_not_equal_v0'
	# conventional flux
	li $v0, 4
	la $a0, done_msg
	syscall
	j exit # jump to 'exit' label

	# LOOP OPERATIONS
	s3_not_equal_s0: j read_input # jump again to 'read_input' label

	# end program
	exit: li $v0, 10 # load immediate syscall to exit (10)
	syscall # system call
