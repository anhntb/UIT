		.data
array1:      	.word	5, 6, 7, 8, 1, 2, 3, 9, 10, 4
size1: 	       	.word 10

array2:     	.byte	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
size2: 	       	.word 16

array3:      	.space	8
size3: 	       	.word 8

s_arr1:		.asciiz	"array1: "
s_arr2:		.asciiz "\narray2: "
chonArr:	.asciiz "\n\nChon array: "
chonVitri:	.asciiz "Chon vi tri phan tu: "
xuat:		.asciiz "Xuat: "

		.text
main:

# in ra cua so I/O tat ca phan tu cua mang array1 va array2
	#array1
		li	$v0, 4
		la	$a0, s_arr1
		syscall
		
		la	$s0, array1
		addi	$s1, $s0, 40	# 10*4 : 1 word = 4 bytes
		
	loop1:	
		li	$v0, 1
		lw	$a0, ($s0)
		syscall
		
		li	$v0, 11
		li	$a0, 32	#space
		syscall
		
		addi	$s0, $s0, 4
		bne	$s0, $s1, loop1
		
		
	#array2
		li	$v0, 4
		la	$a0, s_arr2
		syscall
		
		la	$s0, array2
		addi	$s1, $s0, 16	# 16*1 : 1 byte
		
	loop2:	
		li	$v0, 1
		lb	$a0, ($s0)	#load byte
		syscall
		
		li	$v0, 11
		li	$a0, 32	#space
		syscall
		
		addi	$s0, $s0, 1
		bne	$s0, $s1, loop2
		
		
# gan cac gia tri cho mang array3 sao cho
	#array3[i] = array2[i] + array2[size2 - 1 - i] 
		la	$t0, array2
		subi	$s0, $s0, 1	#dia chi o cuoi cung array2
		
		la	$s1, array3
		addi	$s2, $s1, 8
		
	loop3:
		lb	$a0, ($t0)	#load byte
		lb	$a1, ($s0)
		
		add	$a0, $a0, $a1	# array2[i] + array2[size2 - 1 - i]
		sb	$a0, ($s1)	#store byte
		
		subi	$s0, $s0, 1	# cuoi - 1 (arr2)
		addi	$t0, $t0, 1	# dau + 1 (arr2)
		
		addi	$s1, $s1, 1
		bne	$s1, $s2, loop3
		
		
# nhap vao mang thu may va chi so phan tu, xuat phan tu tuong ung
		li	$v0, 4
		la	$a0, chonArr
		syscall
		
		li	$v0, 5	#read integer
		syscall
		move	$s0, $v0
		
		li	$v0, 4
		la	$a0, chonVitri
		syscall
		
		li	$v0, 5	#read integer
		syscall
		move	$s1, $v0
		
		
	#switch_case_start ($s0: chon array)
		arr1:
			bne	$s0, 1, arr2
			
			li	$t0, 4
			mult	$s1, $t0
			mflo	$t0
			
			la	$t1, array1
			add	$t1, $t1, $t0
			lw	$a1, ($t1)
			
			j	end_switch
			
		arr2:
			bne	$s0, 2, arr3
			
			la	$t1, array2
			add	$t1, $t1, $s1
			lb	$a1, ($t1)
			
			j	end_switch
			
		arr3:
			la	$t1, array3
			add	$t1, $t1, $s1
			lb	$a1, ($t1)
			
	end_switch:
	#switch_case_end
	
	
		li	$v0, 4
		la	$a0, xuat
		syscall
		
		li	$v0, 1
		move	$a0, $a1
		syscall
	
			
				
					
						
							
								
									
										
											
												
													
															
