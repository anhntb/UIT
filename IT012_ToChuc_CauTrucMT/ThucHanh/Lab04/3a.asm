		.data
nhap:		.asciiz "Nhap ky tu: "
truoc:		.asciiz "\nKy tu truoc: "
sau:		.asciiz "\nKy tu sau: "
loai:		.asciiz "\nLoai ki tu: "
so:		.asciiz "So"
thuong:		.asciiz "Chu thuong"
hoa:		.asciiz "Chu hoa"
thongbao:	.asciiz "\nInvalid type"

		.text
main:

	input:
		li	$v0, 4		#print string
		la	$a0, nhap
		syscall
		
		li	$v0, 12		#read character
		syscall
		
		move	$s0, $v0	#save character $s0
		
	check:
		#Number: 48 - 57, 0-9
		#Uppercase: 65 - 90, A-Z
		#Lowercase: 97 - 122, a-z
	
		
		addi	$s1, $s1, 47
		addi	$s2, $s2, 58
		
		addi	$s3, $s3, 64
		addi	$s4, $s4, 91
		
		addi	$s5, $s5, 96
		addi	$s6, $s6, 123
		
		
		slt	$t1, $s1, $s0	#47 < $s0 < 58
		slt	$t2, $s0, $s2
		and	$t3, $t1, $t2
		beq	$t3, 1, loaiSo
		
		slt	$t1, $s3, $s0	#64 < $s0 < 91
		slt	$t2, $s0, $s4
		and	$t3, $t1, $t2
		beq	$t3, 1, loaiHoa
		
		slt	$t1, $s5, $s0	#96 < $s0 < 123
		slt	$t2, $s0, $s6
		and	$t3, $t1, $t2
		beq	$t3, 1, loaiThuong
		j	next
		
	loaiSo:
		la	$t0, so
		j 	next
		
	loaiHoa:
		la	$t0, hoa
		j	next
		
	loaiThuong:
		la	$t0, thuong
		
	next:
		#Ki tu lien truoc, sau
		li	$v0, 4
		la	$a0, truoc
		syscall
		
		subi	$s0, $s0, 1	#print character
		li	$v0, 11
		move	$a0, $s0
		syscall
		
		li	$v0, 4
		la	$a0, sau
		syscall
		
		addi	$s0, $s0, 2	#print character
		li	$v0, 11
		move	$a0, $s0
		syscall
		
		
		#Loai ki tu
		beq	$t0, 0, invalid	#ki tu: invalid type
		
		li	$v0, 4
		la	$a0, loai
		syscall
		
		move	$a0, $t0
		syscall
		j	end
		
	invalid:
		li	$v0, 4
		la	$a0, thongbao
		syscall
		
	end:
		
