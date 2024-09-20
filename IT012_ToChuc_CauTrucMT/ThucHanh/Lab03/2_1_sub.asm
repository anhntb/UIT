		.data 
		.text
		
main:
	#2147483648 = 2^31	0x7fffffff = 2^31-1
	li $t2,-2
	li $t3,0x7fffffff
	

	#sub
	sub $t1,$t2,$t3
	
	#subu : không thông báo overflow
	#subu $t4,$t2,$t3