	.file	"test.cpp"
	.text
	.section	.text$_ZNKSt9type_info4nameEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZNKSt9type_info4nameEv
	.def	_ZNKSt9type_info4nameEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt9type_info4nameEv
_ZNKSt9type_info4nameEv:
.LFB61:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	8(%rax), %rax
	movzbl	(%rax), %eax
	cmpb	$42, %al
	jne	.L2
	movq	16(%rbp), %rax
	movq	8(%rax), %rax
	addq	$1, %rax
	jmp	.L4
.L2:
	movq	16(%rbp), %rax
	movq	8(%rax), %rax
.L4:
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
.lcomm _ZStL8__ioinit,1,1
	.section	.text$_ZN1A4showEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN1A4showEv
	.def	_ZN1A4showEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1A4showEv
_ZN1A4showEv:
.LFB1977:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	_ZTI1A(%rip), %rcx
	call	_ZNKSt9type_info4nameEv
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN1A1SE
	.bss
	.align 4
_ZN1A1SE:
	.space 4
	.text
	.globl	_Z4show1A
	.def	_Z4show1A;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4show1A
_Z4show1A:
.LFB1989:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rcx
	call	_ZN1A4showEv
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z5printv
	.def	_Z5printv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5printv
_Z5printv:
.LFB1990:
	.seh_endprologue
	nop
	ret
	.seh_endproc
	.section	.text$_ZN9Vptr_Vtbl1AC2Eii,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Vptr_Vtbl1AC2Eii
	.def	_ZN9Vptr_Vtbl1AC2Eii;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Vptr_Vtbl1AC2Eii
_ZN9Vptr_Vtbl1AC2Eii:
.LFB1993:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	leaq	16+_ZTVN9Vptr_Vtbl1AE(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movl	24(%rbp), %edx
	movl	%edx, 8(%rax)
	movq	16(%rbp), %rax
	movl	32(%rbp), %edx
	movl	%edx, 12(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9Vptr_Vtbl1AC1Eii,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Vptr_Vtbl1AC1Eii
	.def	_ZN9Vptr_Vtbl1AC1Eii;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Vptr_Vtbl1AC1Eii
_ZN9Vptr_Vtbl1AC1Eii:
.LFB1994:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	leaq	16+_ZTVN9Vptr_Vtbl1AE(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movl	24(%rbp), %edx
	movl	%edx, 8(%rax)
	movq	16(%rbp), %rax
	movl	32(%rbp), %edx
	movl	%edx, 12(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9Vptr_Vtbl1AD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Vptr_Vtbl1AD2Ev
	.def	_ZN9Vptr_Vtbl1AD2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Vptr_Vtbl1AD2Ev
_ZN9Vptr_Vtbl1AD2Ev:
.LFB1996:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTVN9Vptr_Vtbl1AE(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9Vptr_Vtbl1AD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Vptr_Vtbl1AD1Ev
	.def	_ZN9Vptr_Vtbl1AD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Vptr_Vtbl1AD1Ev
_ZN9Vptr_Vtbl1AD1Ev:
.LFB1997:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTVN9Vptr_Vtbl1AE(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9Vptr_Vtbl1A6vfunc1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Vptr_Vtbl1A6vfunc1Ev
	.def	_ZN9Vptr_Vtbl1A6vfunc1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Vptr_Vtbl1A6vfunc1Ev
_ZN9Vptr_Vtbl1A6vfunc1Ev:
.LFB1998:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9Vptr_Vtbl1A6vfunc2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Vptr_Vtbl1A6vfunc2Ev
	.def	_ZN9Vptr_Vtbl1A6vfunc2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Vptr_Vtbl1A6vfunc2Ev
_ZN9Vptr_Vtbl1A6vfunc2Ev:
.LFB1999:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9Vptr_Vtbl1BC2Ei,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Vptr_Vtbl1BC2Ei
	.def	_ZN9Vptr_Vtbl1BC2Ei;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Vptr_Vtbl1BC2Ei
_ZN9Vptr_Vtbl1BC2Ei:
.LFB2003:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	$0, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1AC2Eii
	leaq	16+_ZTVN9Vptr_Vtbl1BE(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movl	24(%rbp), %edx
	movl	%edx, 16(%rax)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9Vptr_Vtbl1BC1Ei,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Vptr_Vtbl1BC1Ei
	.def	_ZN9Vptr_Vtbl1BC1Ei;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Vptr_Vtbl1BC1Ei
_ZN9Vptr_Vtbl1BC1Ei:
.LFB2004:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	$0, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1AC2Eii
	leaq	16+_ZTVN9Vptr_Vtbl1BE(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movl	24(%rbp), %edx
	movl	%edx, 16(%rax)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9Vptr_Vtbl1BD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Vptr_Vtbl1BD2Ev
	.def	_ZN9Vptr_Vtbl1BD2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Vptr_Vtbl1BD2Ev
_ZN9Vptr_Vtbl1BD2Ev:
.LFB2006:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTVN9Vptr_Vtbl1BE(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1AD2Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9Vptr_Vtbl1BD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Vptr_Vtbl1BD1Ev
	.def	_ZN9Vptr_Vtbl1BD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Vptr_Vtbl1BD1Ev
_ZN9Vptr_Vtbl1BD1Ev:
.LFB2007:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTVN9Vptr_Vtbl1BE(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1AD2Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9Vptr_Vtbl1B6vfunc1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Vptr_Vtbl1B6vfunc1Ev
	.def	_ZN9Vptr_Vtbl1B6vfunc1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Vptr_Vtbl1B6vfunc1Ev
_ZN9Vptr_Vtbl1B6vfunc1Ev:
.LFB2008:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9Vptr_Vtbl1CC1Ei,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Vptr_Vtbl1CC1Ei
	.def	_ZN9Vptr_Vtbl1CC1Ei;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Vptr_Vtbl1CC1Ei
_ZN9Vptr_Vtbl1CC1Ei:
.LFB2012:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1BC2Ei
	leaq	16+_ZTVN9Vptr_Vtbl1CE(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movl	24(%rbp), %edx
	movl	%edx, 20(%rax)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9Vptr_Vtbl1CD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Vptr_Vtbl1CD1Ev
	.def	_ZN9Vptr_Vtbl1CD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Vptr_Vtbl1CD1Ev
_ZN9Vptr_Vtbl1CD1Ev:
.LFB2015:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTVN9Vptr_Vtbl1CE(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1BD2Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9Vptr_Vtbl1C6vfunc1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Vptr_Vtbl1C6vfunc1Ev
	.def	_ZN9Vptr_Vtbl1C6vfunc1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Vptr_Vtbl1C6vfunc1Ev
_ZN9Vptr_Vtbl1C6vfunc1Ev:
.LFB2016:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "sizeof A: \0"
.LC1:
	.ascii "sizeof B: \0"
.LC2:
	.ascii "sizeof C: \0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2018:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$120, %rsp
	.seh_stackalloc	120
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	leaq	-32(%rbp), %rax
	movl	$0, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1AC1Eii
	leaq	-64(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1BC1Ei
	leaq	-96(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1CC1Ei
	leaq	.LC0(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
.LEHB0:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$16, %edx
	movq	%rax, %rcx
	call	_ZNSolsEy
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	leaq	.LC1(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$24, %edx
	movq	%rax, %rcx
	call	_ZNSolsEy
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	leaq	.LC2(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$24, %edx
	movq	%rax, %rcx
	call	_ZNSolsEy
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
.LEHE0:
	movl	$0, %ebx
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1CD1Ev
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1BD1Ev
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1AD1Ev
	movl	%ebx, %eax
	jmp	.L26
.L25:
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1CD1Ev
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1BD1Ev
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN9Vptr_Vtbl1AD1Ev
	movq	%rbx, %rax
	movq	%rax, %rcx
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
.L26:
	addq	$120, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA2018:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2018-.LLSDACSB2018
.LLSDACSB2018:
	.uleb128 .LEHB0-.LFB2018
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L25-.LFB2018
	.uleb128 0
	.uleb128 .LEHB1-.LFB2018
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE2018:
	.text
	.seh_endproc
	.globl	_ZTVN9Vptr_Vtbl1CE
	.section	.rdata$_ZTVN9Vptr_Vtbl1CE,"dr"
	.linkonce same_size
	.align 8
_ZTVN9Vptr_Vtbl1CE:
	.quad	0
	.quad	_ZTIN9Vptr_Vtbl1CE
	.quad	_ZN9Vptr_Vtbl1C6vfunc1Ev
	.quad	_ZN9Vptr_Vtbl1A6vfunc2Ev
	.globl	_ZTVN9Vptr_Vtbl1BE
	.section	.rdata$_ZTVN9Vptr_Vtbl1BE,"dr"
	.linkonce same_size
	.align 8
_ZTVN9Vptr_Vtbl1BE:
	.quad	0
	.quad	_ZTIN9Vptr_Vtbl1BE
	.quad	_ZN9Vptr_Vtbl1B6vfunc1Ev
	.quad	_ZN9Vptr_Vtbl1A6vfunc2Ev
	.globl	_ZTVN9Vptr_Vtbl1AE
	.section	.rdata$_ZTVN9Vptr_Vtbl1AE,"dr"
	.linkonce same_size
	.align 8
_ZTVN9Vptr_Vtbl1AE:
	.quad	0
	.quad	_ZTIN9Vptr_Vtbl1AE
	.quad	_ZN9Vptr_Vtbl1A6vfunc1Ev
	.quad	_ZN9Vptr_Vtbl1A6vfunc2Ev
	.globl	_ZTIN9Vptr_Vtbl1CE
	.section	.rdata$_ZTIN9Vptr_Vtbl1CE,"dr"
	.linkonce same_size
	.align 8
_ZTIN9Vptr_Vtbl1CE:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTSN9Vptr_Vtbl1CE
	.quad	_ZTIN9Vptr_Vtbl1BE
	.globl	_ZTSN9Vptr_Vtbl1CE
	.section	.rdata$_ZTSN9Vptr_Vtbl1CE,"dr"
	.linkonce same_size
	.align 8
_ZTSN9Vptr_Vtbl1CE:
	.ascii "N9Vptr_Vtbl1CE\0"
	.globl	_ZTIN9Vptr_Vtbl1BE
	.section	.rdata$_ZTIN9Vptr_Vtbl1BE,"dr"
	.linkonce same_size
	.align 8
_ZTIN9Vptr_Vtbl1BE:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTSN9Vptr_Vtbl1BE
	.quad	_ZTIN9Vptr_Vtbl1AE
	.globl	_ZTSN9Vptr_Vtbl1BE
	.section	.rdata$_ZTSN9Vptr_Vtbl1BE,"dr"
	.linkonce same_size
	.align 8
_ZTSN9Vptr_Vtbl1BE:
	.ascii "N9Vptr_Vtbl1BE\0"
	.globl	_ZTIN9Vptr_Vtbl1AE
	.section	.rdata$_ZTIN9Vptr_Vtbl1AE,"dr"
	.linkonce same_size
	.align 8
_ZTIN9Vptr_Vtbl1AE:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTSN9Vptr_Vtbl1AE
	.globl	_ZTSN9Vptr_Vtbl1AE
	.section	.rdata$_ZTSN9Vptr_Vtbl1AE,"dr"
	.linkonce same_size
	.align 8
_ZTSN9Vptr_Vtbl1AE:
	.ascii "N9Vptr_Vtbl1AE\0"
	.globl	_ZTI1A
	.section	.rdata$_ZTI1A,"dr"
	.linkonce same_size
	.align 8
_ZTI1A:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS1A
	.globl	_ZTS1A
	.section	.rdata$_ZTS1A,"dr"
	.linkonce same_size
_ZTS1A:
	.ascii "1A\0"
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB2509:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB2508:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L30
	cmpl	$65535, 24(%rbp)
	jne	.L30
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
.L30:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I__ZN1A1SE;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__ZN1A1SE
_GLOBAL__sub_I__ZN1A1SE:
.LFB2510:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__ZN1A1SE
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEy;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
