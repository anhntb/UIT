		.data 
		.text
		
main:
	#2147483648 = 2^31	0x7fffffff = 2^31-1
	li $t2,100
	li $t3,5
	
	li $s2,0x7fffffff
	li $s3,5
	

	#add
	add $t1,$t2,$t3
	
	#addi
	addi $t4,$t1,10
	
	#addu : không thông báo overflow
	addu $s1,$s2,$s3
	
	#addiu
	addiu $s4,$s1,10
	
