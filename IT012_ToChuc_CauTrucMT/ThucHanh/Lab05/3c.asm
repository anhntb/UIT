		.data
A:		.space 100
n_A:		.word 0

B:		.space 100
n_B:		.word 0

nhapSL_A:	.asciiz "Nhap so luong phan tu A: "
nhapSL_B:	.asciiz "\nNhap so luong phan tu B: "

		.text
main:
	arrA:
		li	$v0, 4
		la	$a0, nhapSL_A
		syscall
		
		li	$v0, 5
		syscall
		sw	$v0, n_A


		la 	$s0, A		# $s0: first_addressA
		lw	$s1, n_A	# $s1: size(arr)
		subi	$s1, $s1, 1
		addi	$s2, $s2, 4
		
		mult	$s1, $s2
		mflo	$s1
		add	$s1, $s1, $s0	# $s1: last_addressA
		
	nhapA:
		li 	$v0, 5
		syscall
		sw 	$v0, ($s0)
		 
		beq 	$s0, $s1, arrB
		addi 	$s0, $s0, 4
		j 	nhapA
		
	
		
	arrB:	
		move	$s0, $zero
		move	$s1, $zero
		move	$s2, $zero
	
		li	$v0, 4
		la	$a0, nhapSL_B
		syscall
		
		li	$v0, 5
		syscall
		sw	$v0, n_B


		la 	$s0, B		# $s0: first_addressB
		lw	$s1, n_B	# $s1: size(arr)
		subi	$s1, $s1, 1
		addi	$s2, $s2, 4
		
		mult	$s1, $s2
		mflo	$s1
		add	$s1, $s1, $s0	# $s1: last_addressB
		
	nhapB:
		li 	$v0, 5
		syscall
		sw 	$v0, ($s0)
		 
		beq 	$s0, $s1, solve
		addi 	$s0, $s0, 4
		j 	nhapB
		
	
# 	for (i = 2; i < 10; i++)
#		A[i] = B[A[i - 2]];
	solve:
		li	$s0, 2		# i
		la	$s1, A		# (A)
		la	$s2, B		# (B)
		
		
		li	$t0, 4
	loop:
		beq	$s0, 10, exit
		
		mult	$s0, $t0
		mflo	$t1
		add	$t1, $t1, $s1	# (A + i)
		subi	$t1, $t1, 8	# (A + i - 2)
		
		lw	$s4, ($t1)	# A[i-2]
		
		mult	$s4, $t0
		mflo	$s4
		add	$s4, $s4, $s2	# (B + A[i-2])
		lw	$s3, ($s4)	# B[A[i-2]]
		
		sw	$s3, 8($t1)
		
		addi	$s0, $s0, 1	# i++
		j	loop
		
		
	exit:
	
	
