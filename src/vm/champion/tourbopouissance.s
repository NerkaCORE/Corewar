.name "TourboPouissance"
.comment "On Enclenche la TourboPouissance"

start:
	lfork %2048
	sti r1, %:live, %1
	ld %653312, r8
wall:
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	st	r8,-200
	ld	%0,r15
init_live:
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
	st r1, 101
live:
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	ld %0, r16
	zjmp %:live
