	.file	"1threads.c"
	.intel_syntax noprefix
	.text
	.globl	cnt
	.bss
	.align 4
	.type	cnt, @object
	.size	cnt, 4
cnt:
	.zero	4
	.text
	.globl	myTask1
	.type	myTask1, @function
myTask1:
.LFB6:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR -8[rbp], 0
	jmp	.L2
.L3:
	mov	eax, DWORD PTR cnt[rip]
	add	eax, 1
	mov	DWORD PTR cnt[rip], eax
	add	QWORD PTR -8[rbp], 1
.L2:
	cmp	QWORD PTR -8[rbp], 99999
	jbe	.L3
	mov	eax, 0
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	myTask1, .-myTask1
	.section	.rodata
.LC0:
	.string	"Count: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -8[rbp], rax
	xor	eax, eax
	lea	rax, -24[rbp]
	mov	ecx, 0
	lea	rdx, myTask1[rip]
	mov	esi, 0
	mov	rdi, rax
	call	pthread_create@PLT
	test	eax, eax
	jns	.L6
	call	__errno_location@PLT
	mov	eax, DWORD PTR [rax]
	mov	edi, eax
	call	exit@PLT
.L6:
	lea	rax, -16[rbp]
	mov	ecx, 0
	lea	rdx, myTask1[rip]
	mov	esi, 0
	mov	rdi, rax
	call	pthread_create@PLT
	test	eax, eax
	jns	.L7
	call	__errno_location@PLT
	mov	eax, DWORD PTR [rax]
	mov	edi, eax
	call	exit@PLT
.L7:
	mov	rax, QWORD PTR -24[rbp]
	mov	esi, 0
	mov	rdi, rax
	call	pthread_join@PLT
	test	eax, eax
	jns	.L8
	call	__errno_location@PLT
	mov	eax, DWORD PTR [rax]
	mov	edi, eax
	call	exit@PLT
.L8:
	mov	rax, QWORD PTR -16[rbp]
	mov	esi, 0
	mov	rdi, rax
	call	pthread_join@PLT
	test	eax, eax
	jns	.L9
	call	__errno_location@PLT
	mov	eax, DWORD PTR [rax]
	mov	edi, eax
	call	exit@PLT
.L9:
	mov	eax, DWORD PTR cnt[rip]
	mov	esi, eax
	lea	rax, .LC0[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	mov	eax, 0
	mov	rdx, QWORD PTR -8[rbp]
	sub	rdx, QWORD PTR fs:40
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits
