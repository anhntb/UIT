		.data
nhap:		.asciiz "Nhap: "
xuatCD:		.asciiz "\nChieu dai chuoi: "
		
		.text
main:
		li $t1,9 #tab
		
		li $v0,4
		la $a0,nhap
		syscall
		
	nhapC:
		li $v0,12
		syscall
		
		beq $t1,$v0,xuatCDai
		addi $s0,$s0,1
		j nhapC
	
	xuatCDai:
		li $v0,4
		la $a0,xuatCD
		syscall	
		
		li $v0,1
		move $a0,$s0
		syscall