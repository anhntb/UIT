		.data
arr:		.space 16
n1:		.asciiz "So thu nhat: "
n2: 		.asciiz "So thu hai: "
sLon:		.asciiz "So lon hon: "
tong:		.asciiz "\nTong: "
hieu1:		.asciiz "\nHieu n1 - n2: "
hieu2:		.asciiz "\nHieu n2 - n1: "
tich:		.asciiz "\nTich: "
thuong1: 	.asciiz "\nThuong n1 / n2: "
thuong2:	.asciiz "\nThuong n2 / n1: "

		.text
main:
		li 	$v0, 4
		la	$a0, n1
		syscall
		
		li	$v0, 5
		syscall
		
		move	$s1, $v0	#save integer $s1
		
		
		li 	$v0, 4
		la	$a0, n2
		syscall
		
		li	$v0, 5
		syscall
		
		move	$s2, $v0	#save integer $s2
		
		
	#So lon hon
		li 	$v0, 4
		la	$a0, sLon
		syscall
		
		slt	$s0, $s1, $s2	#1: n1 < n2	0: n1 >= n2
		beq	$s0, 1, sLon2
		move	$a0, $s1
		j	next
	sLon2:
		move	$a0, $s2	
	next:
		li	$v0, 1
		syscall 
		
		
	#Tong
		li 	$v0, 4
		la	$a0, tong
		syscall
		
		add	$a0, $s1, $s2
		li	$v0, 1
		syscall
		
		
	#Hieu
		li 	$v0, 4
		la	$a0, hieu1
		syscall
		
		sub	$a0, $s1, $s2
		li	$v0, 1
		syscall
		
		
		li 	$v0, 4
		la	$a0, hieu2
		syscall
		
		sub	$a0, $s2, $s1
		li	$v0, 1
		syscall
		
		
	#Tich
		li 	$v0, 4
		la	$a0, tich
		syscall
		
		mult	$s1, $s2
		mflo	$a0
		li	$v0, 1
		syscall
		
		
	#Thuong
		li 	$v0, 4
		la	$a0, thuong1
		syscall
		
		div	$s1, $s2
		mflo	$a0
		li	$v0, 1
		syscall
		
		li 	$v0, 4
		la	$a0, thuong2
		syscall
		
		div	$s2, $s1
		mflo	$a0
		li	$v0, 1
		syscall
		
		