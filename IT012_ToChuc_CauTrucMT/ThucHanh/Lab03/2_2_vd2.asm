		.data
array1:		.space	12	#T?o m?t m?ng tên array1 có 12 bytes liên t?c nhau v?i lýu tr? chýa kh?i t?o
		.text
__start:	la	$t0,array1	#load ð?a ch? (0x1001 0000)
		li	$t1,5		#gán $t1=5
		sw $t1,($t0)		#lýu giá tr? t? $t1 sang ô nh? có ð?a ch? (0x1001 0000)
		li $t1,13		#gán $t1=13
		sw $t1,4($t0)		#lýu giá tr? t? $t1 sang ô nh? có ð?a ch? (0x1001 0000) + 4
		li $t1,-7		#gán $t1=-7
		sw $t1,8($t0)		#lýu giá tr? t? $t1 sang ô nh? có ð?a ch? (0x1001 0000) + 8
		
		#lýu l?n lý?t các giá tr? 5,13,-7 vào ô nh?, b?t ð?u t? (0x1001 0000)