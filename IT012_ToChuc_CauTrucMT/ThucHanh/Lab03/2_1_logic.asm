		.data 
		.text
		
main:
	#so sánh theo t?ng bit
	li $t2,0x123
	li $t3,0x0ff
	
	li $s2,0x456
	li $s3,0x0ff
	
	
	#and
	and $t1,$t2,$t3
	
	#andi
	andi $t4,$t2,0xf0f
	
	#or
	or $s1,$s2,$s3
	
	#nor
	nor $s4,$s2,$s3