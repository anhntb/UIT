		.data
string1:	.asciiz	"Print this.\n"

		.text
main:		li	$v0,4

		la	$a0,string1	#load ð?a ch? string1 vào $a0
		syscall
		
		#in d?ng ch? "Print this.\n" ra màn h?nh