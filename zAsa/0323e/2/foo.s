	.file	"foo.cc"
	.text
	.p2align 4
	.globl	_Z3fooi
	.type	_Z3fooi, @function
_Z3fooi:
.LFB930:
	.cfi_startproc
	endbr64
	testl	%edi, %edi
	jle	.L13
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pxor	%xmm2, %xmm2
	imull	$2756, %edi, %edi
	movl	$1538, %ebp
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movapd	%xmm2, %xmm1
	movl	$2756, %ebx
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	jmp	.L6
	.p2align 4,,10
	.p2align 3
.L5:
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%ebx, %xmm0
	addsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%ebp, %xmm0
	ucomisd	%xmm0, %xmm2
	ja	.L14
.L4:
	addl	$2756, %ebx
	addl	$1538, %ebp
.L6:
	cmpl	%edi, %ebx
	jne	.L5
	addq	$24, %rsp
	.cfi_def_cfa_offset 24
	movapd	%xmm1, %xmm0
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L13:
	.cfi_restore 3
	.cfi_restore 6
	pxor	%xmm1, %xmm1
	movapd	%xmm1, %xmm0
	ret
.L14:
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	movl	%edi, 4(%rsp)
	movsd	%xmm1, 8(%rsp)
	call	sqrt@PLT
	movsd	8(%rsp), %xmm1
	movl	4(%rsp), %edi
	pxor	%xmm2, %xmm2
	jmp	.L4
	.cfi_endproc
.LFE930:
	.size	_Z3fooi, .-_Z3fooi
	.p2align 4
	.globl	_Z3barv
	.type	_Z3barv, @function
_Z3barv:
.LFB931:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pxor	%xmm2, %xmm2
	movl	$1538, %ebp
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movapd	%xmm2, %xmm1
	movl	$2756, %ebx
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	.p2align 4,,10
	.p2align 3
.L17:
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%ebx, %xmm0
	addsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%ebp, %xmm0
	ucomisd	%xmm0, %xmm2
	ja	.L20
.L16:
	addl	$2756, %ebx
	addl	$1538, %ebp
	cmpl	$27560, %ebx
	jne	.L17
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	cvttsd2sil	%xmm1, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L20:
	.cfi_restore_state
	movsd	%xmm1, 8(%rsp)
	call	sqrt@PLT
	movsd	8(%rsp), %xmm1
	pxor	%xmm2, %xmm2
	jmp	.L16
	.cfi_endproc
.LFE931:
	.size	_Z3barv, .-_Z3barv
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
