# i = $s0				if(i == j)
# j = $s1					f = g + h;
# f = $s2				else
# g = $t0					f = g - h;
# h = $t1	
			
		.data
		.text
main:
		addi $s0,$s0,10	#i
		addi $s1,$s1,11	#j
		addi $t0,$t0,20	#g
		addi $t1,$t1,10	#h


		beq $s0,$s1,next	#if(i == j)
		sub $s2,$t0,$t1		#f = g - h;
		j exit			
	next:
		add $s2,$t0,$t1		#f = g + h;
		
	exit: