		.data
nhap:		.asciiz "Nhap: "
xuat:		.asciiz "Xuat: "
str:		.space	50 #50 kí t?

		.text
main:
		#Nh?p chu?i
		li $v0,4
		la $a0,nhap
		syscall
		
		li $v0,8
		li $a1,50
		la $a0,str
		syscall
		
		move $s1, $a0
		
		
		#Xu?t chu?i
		li $v0,4
		la $a0,xuat
		syscall
		
		li $v0,4
		la $a0,($s1)
		syscall
		