.data
arr:		.space 100
size:		.word 0

nhapSL:		.asciiz "Nhap so luong phan tu: "

		.text
main:
		li	$v0, 4
		la	$a0, nhapSL
		syscall
		
		li	$v0, 5
		syscall
		sw	$v0, size
		beq	$v0, 0, exit	# size(arr) = 0	     => ket thuc


		la 	$s0, arr	# $s0: first_address
		lw	$s1, size	# $s1: size(arr)
		subi	$s1, $s1, 1
		addi	$s2, $s2, 4
		
		mult	$s1, $s2
		mflo	$s1
		add	$s1, $s1, $s0	# $s1: last_address
		
	nhap:
		li 	$v0, 5
		syscall
		sw 	$v0, ($s0)
		 
		beq 	$s0, $s1, solve
		addi 	$s0, $s0, 4
		j 	nhap
		
		
#	if (i < j) A[i] = i;
#	else A[i] = j;
	solve:
		li	$s0, 4	# i
		li	$s1, 3	# j
		la	$s3, arr
	
		li	$t0, 4
		mult	$s0, $t0
		mflo	$t0
		add	$t0, $t0, $s3	# $t0 = (A + i)
		lw	$t1, ($t0)	# $t0 = *(A + i) = A[i]
	
	if:
		slt	$s2, $s0, $s1
		bne	$s2, 1, else
		
		move	$t1, $s0
		j 	store
	else:
		move	$t1, $s1
	
	store:
		sw	$t1, ($t0)
		
		
	exit:
		
		
		
		