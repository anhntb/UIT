# i = $s0					int Sum = 0;
# N = $s1					for (int i=1; i <= N; ++i)
# Sum = $s2						Sum = Sum + i;

		.data
		.text
main:
		addi $s1,$s1,5 #N
		
		
		add $s2,$s2,$zero #int Sum = 0;
		
		addi $s0,$s0,1 #int i = 1;
		addi $t1,$s1,1 #N+1
	
	loop:
		slt $t0,$s0,$t1 #$t0: boolean (i < N+1)
		bne $t0,1,exit #neu !(i < N+1) thi exit
		add $s2,$s2,$s0
		addi $s0,$s0,1
		j loop
		
	exit:
		