		.data 
		.text
main:
	 li $t2,-10
	 li $t3,5
	 
	 li $s2,-10
	 li $s3,5
	 
	 #slt
	 slt $t0,$t2,$t3
	 
	 #slti
	 slti $t1,$t2,-11
	 
	 #sltu: so sánh không d?u
	 sltu $s0,$s2,$s3
	 
	 #sltiu
	 sltiu $s1,$s2,-30