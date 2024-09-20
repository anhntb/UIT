		.data
str:		.space 400
nhap:		.asciiz "Nhap: "
xuat:		.asciiz "\nXuat: "
		
		.text
main:
		la $s1,str
		la $s2,($s1)
		li $t1,9 #tab
		
		li $v0,4
		la $a0,nhap
		syscall
		
	nhapC:
		li $v0,12
		syscall
		
		beq $t1,$v0,xuatC
		sw $v0,($s2)
		addi $s2,$s2,4
		j nhapC
		
	xuatC:
		li $v0,4
		la $a0,xuat
		syscall
		
	daonguoc:
		lw $a0,($s2)
		li $v0,11
		syscall
		beq $s1,$s2,exit
		
		addi $s2,$s2,-4
		j daonguoc
		
	exit:
			