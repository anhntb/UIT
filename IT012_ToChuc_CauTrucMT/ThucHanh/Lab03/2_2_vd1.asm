		.data
var1:		.word	23

		.text
__start:
		lw	$t0,var1	#load word t? var1 vào $t0
		li	$t1,5		#gán $t1=5
		sw	$t1,var1	#lýu giá tr? $t1 vào ô nh? có ð?a ch? var1
		
		#var1 là ð?a ch? ð?u tiên (0x1001 0000) có giá tr? 23 ban ð?u và b?ng 5 khi k?t thúc