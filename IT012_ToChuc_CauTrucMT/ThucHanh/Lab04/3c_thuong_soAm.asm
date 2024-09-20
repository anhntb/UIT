#	ket qua khong mong muon
		
		.data
arr:		.space 16
n1:		.asciiz "So thu nhat: "
n2: 		.asciiz "So thu hai: "
thuong1: 	.asciiz "Thuong n1 / n2: "
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

	#Thuong
		la	$s0, arr
		sw	$s1, ($s0)
		sw	$s2, 8($s0)
		
		ldc1	$f2, ($s0)	#chuyen n1, n2 sang float
		ldc1	$f4, 8($s0)
		
		
		li 	$v0, 4
		la	$a0, thuong1
		syscall
		
		div.d	$f12, $f2, $f4
		li	$v0, 2
		syscall
		
		
		li 	$v0, 4
		la	$a0, thuong2
		syscall
		
		div.d	$f12, $f4, $f2
		li	$v0, 2
		syscall
		
		