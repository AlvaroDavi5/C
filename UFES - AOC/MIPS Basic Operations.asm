# MIPS 32
  # Registers:
    # All Registers:
      # $zero - zero constant register
      # $at - assembler temporary register
      # $v0, $v1 - function return registers
      # $a0, ..., $a3 - function arguments registers
      # $t0, ..., $t9 - temporary registers
      # $s0, ..., $s7 - storage registers
      # $f0, ..., $f31 - floating values registers (coprocessor 1)
      # $k0, $k1 - kernel interruption/exception registers
      # $gp - global/static data address pointer register
      # $sp - stack address pointer register
      # $fp - frame (stack current procedure) address pointer register
      # $ra - return address for previous instruction register
      # lo - low-order (integer part from the division) register
      # hi - high-order (rest of the division) register
      # pc - current/next instruction address pointer register
    # Registers are enumerated: $zero=$0, $t0=8, $s0=16...

  # Syscall Codes:
    # Print
      # 1 - int
      # 2 - float
      # 3 - double
      # 4 - string
    # Read
      # 5 - int
      # 6 - float
      # 7 - double
      # 8 - string
    # Exit
      # 10 - exit

  # Memory Layout Segments:
    # Kernel Level
      # Reserved
      # Memory Mapped IO: Store memory mapped registers for IO devices
      # Data
      # Text
      # Reserved (last address)
    # Program Level
      # Text: Store user level code/instructions
      # Data: Store static/global data (data know at compile time) used by the user program
      # Heap [dynamic]: Store dynamic data (data allocated during runtime) used by the user program
      # Stack [dynamic]: Store temporary data (parameters, local variables, return address for function/subroutine calls) used by the user program
      # Free: Unallocated, generally used by Heap or Stack

  # Instructions Encoding:
    #  operation      src reg      src reg       dest reg      shift amount     ALU function
    # op (6 bits) | rs (5 bits) | rt (5 bits) | rd (5 bits) | shamt (5 bits) | funct (6 bits)


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
	la $t2, 0($s0)
	subi $s0, $s0, 3 # $s0 -= 3
	li $t4, 2
	la $t3, 0($s0)
	mul $t5, $t3, $t4 # $t5 = $t3 * $t4
	li $t6, 7
	div $t7, $t5, $t6 # $t7 = $t5 / $t6
	mflo $s1 # move from 'lo' register
	mfhi $s2 # move from 'hi' register
	sll $t8, $t5, 1 # $t8 = $t5 * 2^1, $t8 = $t5 << 1
	move $s0, $t8 # $t8 → $s0

	# MEMORY LOAD/STORE OPERATIONS
	# load address
	la $t8, var1 # $t8 = var1.addr
	# load word
	lw $t9, var1 # $t9 = var1.word
	# store word
	sw $s0, 0($t8) # MEM[$t8] = $s0
	sw $t9, 4($t8) # MEM[$t8+4] = $t9, increased 4 to access next word because each word has 4 bytes (32/8 [bits] = 4 [bytes])

	# SYSTEM CALLS OPERATIONS
	# print string
	li $v0, 4 # load immediate syscall to print_string (4) on '$v0' register
	la $a0, msg
	syscall
	li $v0, 4
	la $a0, linebreak
	syscall
	# print integer
	li $v0, 1 # load immediate syscall to print_int (1)
	lw $a0, date
	syscall
	li $v0, 4
	la $a0, linebreak
	syscall
	# print float
	li $v0, 2 # load immediate syscall to print_float (2)
	lwc1 $f12, pi # load word from coprocessor 1
	syscall
	li $v0, 4
	la $a0, linebreak
	syscall

	read_input:
	li $v0, 4
	la $a0, read_int_msg
	syscall
	# read integer
	li $v0, 5 # load immediate syscall to read_int (5) and save on '$v0' register
	syscall
	add $s3, $v0, $zero

	# CONDITION FLUX OPERATIONS
	bne $s3, $s0, s3_not_equal_s0 # flux changed by label 's3_not_equal_s0'
	# conventional flux
	li $v0, 4
	la $a0, done_msg
	syscall
	j exit # jump to 'exit' label

	# LOOP OPERATIONS
	s3_not_equal_s0: j read_input # jump again to 'read_input' label

	# end program
	exit:
	li $v0, 10 # load immediate syscall to exit (10)
	syscall # system call
