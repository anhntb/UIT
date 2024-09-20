#Viet chuong trinh tim gia tri lon nhat trong mang A co 10 phan tu. Biet mang A co base address luu tai thanh ghi $s0. Ket qua tim duoc luu vao thanh ghi $s1.

		.data
arr:		.space 40
		.text
main:
		la $s0,arr
		move $t0,$s0 #$t0 la dia chi chay
		
	nhap:
		
		li $v0,5
		syscall
		sw $v0,($t0)
		
		beq $t1,9,timMax
		addi $t1,$t1,1 #$t1 la bien dem
		addi $t0,$t0,4
		j nhap
		
	timMax:
		lw $s1,($s0)
		
		loop:
			lw $s2,($t0) #$s2 la bien so sanh
			
			slt $s3,$s1,$s2 #$s3 luu 1 va 0
			beq $s3,0,next
			move $s1,$s2
			next:
				addi $t0,$t0,-4
				bne $t0,$s0,loop
			