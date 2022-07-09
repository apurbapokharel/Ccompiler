	.text
.LC0:
	.string	"%d\n"
printint:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	ret

	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	.comm	fred,8,8
	.comm	jon,8,8
	movq	$1, %r8
	movq	$2, %r9
	movq	$3, %r10
	imulq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, fred(%rip)
	movq	$9, %r8
	movq	%r8, jon(%rip)
	movq	fred(%rip), %r8
	movq	jon(%rip), %r9
	addq	%r8, %r9
	movq	%r9, %rdi
	call	printint
	movl	$0, %eax
	popq	%rbp
	ret
