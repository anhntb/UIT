		.data
arr:		.space 40
nhap:		.asciiz "Nhap: "
xuat:		.asciiz "Xuat:"
thongbao:	.asciiz "invalid Entry"
_0:		.asciiz " Zero"
_1:		.asciiz " One"
_2:		.asciiz " Two"
_3:		.asciiz " Three"
_4:		.asciiz " Four"
_5:		.asciiz " Five"
_6:		.asciiz " Six"
_7:		.asciiz " Seven"
_8:		.asciiz " Eight"
_9:		.asciiz " Nine"

		.text
main:
#input
		li	$v0, 4
		la	$a0, nhap
		syscall
		
		li	$v0, 5
		syscall
		
		move	$s0, $v0	#save integer $s0
		
		
#check: la so nguyen duong?
		slt	$t0, $zero, $s0	#$t0: boolean		0: 0 >= $s0	1: 0 < $s0
		beq	$t0, 0, invalid
		
		
#output
		li	$v0, 4
		la	$a0, xuat
		syscall
		
		
		la	$t1, arr
		addi	$t3, $t3, 10
	saveNum:
		div	$s0, $t3
		mflo	$s0	# $s0 /= 10
		mfhi	$s1	# $s1 = $s0 % 10	
		
		sw	$s1, ($t1)
		beq	$s0, $zero, printNum_Name
		addi	$t1, $t1, 4
		j	saveNum
		
		
	printNum_Name:
		lw	$s1, ($t1)
		
	#switch_case_start
		n0:
			bne	$s1, 0, n1	#$s1 <> 0 thi tiep tuc so sanh (to label n1)
			la	$a0, _0
			j	print		#break
			
		n1:
			bne	$s1, 1, n2	
			la	$a0, _1
			j	print
			
		n2:
			bne	$s1, 2, n3	
			la	$a0, _2
			j	print
			
		n3:
			bne	$s1, 3, n4
			la	$a0, _3
			j	print
			
		n4:
			bne	$s1, 4, n5	
			la	$a0, _4
			j	print
			
		n5:
			bne	$s1, 5, n6	
			la	$a0, _5
			j	print
			
		n6:
			bne	$s1, 6, n7	
			la	$a0, _6
			j	print
			
		n7:
			bne	$s1, 7, n8	
			la	$a0, _7
			j	print
			
		n8:
			bne	$s1, 8, n9	
			la	$a0, _8
			j	print
			
		n9:	
			la	$a0, _9
			
		print:
			li	$v0, 4
			syscall
	#switch_case_end		
		
		beq	$t1, 0x10010000, end
		subi	$t1, $t1, 4
		j	printNum_Name
	
		
	invalid:
		li	$v0, 4
		la	$a0, thongbao
		syscall
	
	end:
		
		
