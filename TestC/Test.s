	.file	"Test.c"
	.text
	.globl	_get
	.def	_get;	.scl	2;	.type	32;	.endef
_get:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
	jmp	L2
L4:
	movl	-12(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -12(%ebp)
	movl	-16(%ebp), %edx
	movb	%dl, (%eax)
L2:
	call	_getchar
	movl	%eax, -16(%ebp)
	cmpl	$10, -16(%ebp)
	je	L3
	cmpl	$-1, -16(%ebp)
	jne	L4
L3:
	cmpl	$-1, -16(%ebp)
	jne	L5
	movl	-12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jne	L5
	movl	$0, %eax
	jmp	L6
L5:
	movl	-12(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -12(%ebp)
	movb	$0, (%eax)
	movl	8(%ebp), %eax
L6:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.globl	_echo
	.def	_echo;	.scl	2;	.type	32;	.endef
_echo:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_gets
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_getchar;	.scl	2;	.type	32;	.endef
	.def	_gets;	.scl	2;	.type	32;	.endef
