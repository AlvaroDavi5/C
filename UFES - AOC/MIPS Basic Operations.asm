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


.text # instructions segment

	# arithmetic operations
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
	mflo $s1 # move from low-order
	mfhi $s2 # move from high-order
	sll $t8, $t5, 1 # $t8 = $t5 * 2^1, $t8 = $t5 << 1
	move $s0, $t8 # $t8 → $s0

	# memory load/store operations
	#lw $t9, 0($s0)

	# print string
	li $v0, 4 # load immediate string (4)
	la $a0, msg # load address
	syscall
	li $v0, 4
	la $a0, linebreak
	syscall
	# print integer
	li $v0, 1 # load immediate integer (1)
	lw $a0, date # load world
	syscall
	li $v0, 4
	la $a0, linebreak
	syscall
	# print float
	li $v0, 2 # load immediate float (2)
	lwc1 $f12, pi # load word into coprocessor 1
	syscall
	li $v0, 4
	la $a0, linebreak
	syscall

	# end program
	li $v0, 10 # load immediate end program
	syscall # system call
