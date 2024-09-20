		.data
arr:		.space 200

		.text
main:
		addi	$t0, $t0, 4	#integer: 4 bytes

		addi	$s0, $s0, 3	#size A: so phan tu
		addi	$s1, $s1, 4	#size B: so phan tu
		
		la	$s2, arr	#dia chi A
		mult	$s0, $t0
		mflo	$t1		#size A theo bytes
		
		add	$s3, $s2, $t1	#dia chi B
		
		
		li	$t3, 0	#dem phan tu nhap vao A
		la	$t4, ($s2)	#bien dia chi A
	inputA:
		beq	$t3, $s0, next1
	
		li	$v0, 5
		syscall
		
		move	$t5, $v0
		sw	$t5, ($t4)
		addi	$t4, $t4, 4
		addi	$t3, $t3, 1
		j	inputA
		
	next1:
		li	$t3, 0	#dem phan tu nhap vao B
		la	$t4, ($s3)	#bien dia chi B
	inputB:
		beq	$t3, $s1, next2
	
		li	$v0, 5
		syscall
		
		move	$t5, $v0
		sw	$t5, ($t4)
		addi	$t4, $t4, 4
		addi	$t3, $t3, 1
		j	inputB
#Cau a:	
	next2:
		lw	$s4, ($s2)
		
		move	$t3, $zero	#dem phan tu nhap vao A
		la	$t4, ($s2)	#bien dia chi A
	loopA:
		lw	$t6, ($t4)
		
		slt	$t7, $s4, $t6
		beq	$t7, 1, swap
		j	else
	swap:
		move	$s4, $t6
	else:
		beq	$t3, $s0, next3
		addi	$t4, $t4, 4
		addi	$t3, $t3, 1
		j	loopA
		
#Cau b:
	next3:
	
#Cau c: thuc hien doan ma
		li	$t5, 0 #i
	loop:
		slt	$t6, $t5, $s0
		
		
		
		
		
		
		
		
		
	