		.data
arr:		.space 100
size:		.word 0

nhapSL:		.asciiz "Nhap so luong phan tu: "
max:		.asciiz "\nMAX = "
min:		.asciiz "\t\tMIN = "
tong:		.asciiz "\t\tTONG = "
nhapChiSo:	.asciiz "\n\nChi so phan tu: "
text1:		.asciiz "arr["
text2:		.asciiz "]: "

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
		
	
# tim max, min, tinh tong
	solve:
		la 	$s0, arr	# $s0: first_address	/	$s1: last_address
		lw	$t1, ($s0)	# max
		lw	$t2, ($s0)	# min
		lw	$t3, ($s0)	# tong
		
		lw	$t4, size
		beq	$t4, 1, xuat	# mang chi co 1 phan tu
		
		loop:
			addi	$s0, $s0, 4
			lw 	$t0, ($s0) # $t0: bien so sanh
			
			slt 	$t4, $t1, $t0	# $t4: bool_max
			slt	$t5, $t0, $t2	# $t5: bool_min
			add	$t3, $t3, $t0
			
			beq 	$t4, 1, changeMax
			beq 	$t5, 1, changeMin
			j	next
			
			changeMax:
				move	$t1, $t0
				beq 	$t5, 1, changeMin
				j next
				
			changeMin:
				move	$t2, $t0
				
			next:
				bne	$s0, $s1, loop
				
				
	xuat:
		li	$v0, 4
		la	$a0, max
		syscall
		
		li	$v0, 1
		move 	$a0, $t1
		syscall
		
		li	$v0, 4
		la	$a0, min
		syscall
		
		li	$v0, 1
		move 	$a0, $t2
		syscall
		
		li	$v0, 4
		la	$a0, tong
		syscall
		
		li	$v0, 1
		move 	$a0, $t3
		syscall
		
		
# nhap vao chi so phan tu, in ra gia tri tuong ung
		li	$v0, 4
		la	$a0, nhapChiSo
		syscall
		
		li	$v0, 5
		syscall
		move	$s2, $v0
		
		li	$s1, 4
		mult	$s1, $s2
		mflo	$s1
		
		la	$s0, arr
		add	$s0, $s0, $s1	# $s0: dia chi phan tu can in
		
		li	$v0, 4
		la	$a0, text1
		syscall
		
		li	$v0, 1
		move	$a0, $s2
		syscall
		
		li	$v0, 4
		la	$a0, text2
		syscall
		
		li	$v0, 1
		lw	$a0, ($s0)
		syscall

	exit:
			
			
		