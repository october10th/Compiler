	.text
	.align	2
	.global	sub
	.type	sub, @function
sub:
	push.s	{ $fp $lp }
	addi	$fp, $sp, 8
	addi	$sp, $sp, -16
	swi	$r0, [$fp+(-20)]
	swi	$r1, [$fp+(-24)]
	addi	$r1, $r0, 0
	movi	$r0 ,0
	swi	$r0, [$fp+(-12)]
	addi	$r1, $r0, 0
	movi	$r0 ,1
	swi	$r0, [$fp+(-16)]
	addi	$r1, $r0, 0
	lwi	$r0, [$fp+(-20)]
	addi	$r1, $r0, 0
	lwi	$r0, [$fp+(-24)]
	sub	$r0, $r1, $r0
	addi	$r1, $r0, 0
	lwi	$r0, [$fp+(-12)]
	sub	$r0, $r1, $r0
	addi	$r1, $r0, 0
	lwi	$r0, [$fp+(-16)]
	sub	$r0, $r1, $r0
	addi	$sp, $fp, -8
	pop.s	{ $fp $lp }
	ret
	.size	sub, .-sub
	.align	2
	.global	main
	.type	main, @function
main:
	push.s	{ $fp $lp }
	addi	$fp, $sp, 8
	addi	$sp, $sp, -16
	addi	$r1, $r0, 0
	movi	$r0 ,1
	swi	$r0, [$fp+(-16)]
	addi	$r1, $r0, 0
	movi	$r0 ,2
	swi	$r0, [$fp+(-20)]
	addi	$r1, $r0, 0
	movi	$r0 ,3
	swi	$r0, [$fp+(-24)]
	addi	$r1, $r0, 0
	movi	$r0 ,10
	addi	$r1, $r0, 0
	movi	$r0 ,2
	divsr	$r0, $r1, $r1, $r0
	swi	$r0, [$fp+(-12)]
	addi	$r1, $r0, 0
	lwi	$r0, [$fp+(-16)]
	addi	$r1, $r0, 0
	movi	$r0 ,3
	add	$r0, $r1, $r0
	addi	$r1, $r0, 0
	movi	$r0 ,4
	mul	$r0, $r1, $r0
	addi	$r1, $r0, 0
	movi	$r0 ,5
	sub	$r0, $r1, $r0
	swi	$r0, [$fp+(-20)]
	movi	$r0 ,10
	movi	$r1 ,8
	jal	sub
	swi	$r0, [$fp+(-16)]
	addi	$r1, $r0, 0
	movi	$r0 ,0
	addi	$sp, $fp, -8
	pop.s	{ $fp $lp }
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.9.0"
