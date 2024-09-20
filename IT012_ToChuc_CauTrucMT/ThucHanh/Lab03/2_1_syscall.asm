		.data 
str:		.asciiz "abcd\n"
		
		.text
main:
		#in chu?i
		la $a0,str
		li $v0,4
		syscall
		
		#nh?p s?
		li $v0,5
		syscall
		
		move $t1,$v0

		#Dùng ð? yêu c?u d?ch v? t? kernel, 
		#m? d?ch v? ðý?c truy?n t? thanh ghi $v0