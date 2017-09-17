	.file	"sorting.cc"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	_Z13insertionSortRSt6vectorIfSaIfEE
	.type	_Z13insertionSortRSt6vectorIfSaIfEE, @function
_Z13insertionSortRSt6vectorIfSaIfEE:
.LFB740:
	.cfi_startproc
	movq	(%rdi), %rdx
	movq	8(%rdi), %rax
	xorl	%ecx, %ecx
	subq	%rdx, %rax
	sarq	$2, %rax
	cmpq	$1, %rax
	leaq	-1(%rax), %rsi
	jbe	.L1
	.p2align 4,,10
	.p2align 3
.L10:
	movss	4(%rdx,%rcx,4), %xmm1
	movq	%rcx, %rax
	movss	(%rdx,%rcx,4), %xmm0
	ucomiss	%xmm1, %xmm0
	jbe	.L14
	.p2align 4,,10
	.p2align 3
.L11:
	movss	%xmm0, 4(%rdx,%rax,4)
	subq	$1, %rax
	movss	(%rdx,%rax,4), %xmm0
	ucomiss	%xmm1, %xmm0
	ja	.L11
	addq	$1, %rcx
	movss	%xmm1, 4(%rdx,%rax,4)
	cmpq	%rsi, %rcx
	jne	.L10
.L1:
	rep ret
.L14:
	movq	%rcx, %rax
	addq	$1, %rcx
	cmpq	%rsi, %rcx
	movss	%xmm1, 4(%rdx,%rax,4)
	jne	.L10
	jmp	.L1
	.cfi_endproc
.LFE740:
	.size	_Z13insertionSortRSt6vectorIfSaIfEE, .-_Z13insertionSortRSt6vectorIfSaIfEE
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
