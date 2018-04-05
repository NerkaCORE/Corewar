.name "zork"
.comment "I'M ALIIIIVE"

#live %1
#live %1
#live %1
#live %1
#live %1
#live %1
move:
	ld %255, r2
	st r1, 256
	st r1, 511
	st r1, 513
    fork %:l2
	zjmp %:fire
fire:
    live %0
    ld %420, r3
    fork %:live
    st r1, -1000
    st r1, -1000
    st r1, -1000
    st r1, -1000
    zjmp %:l2
 l2:
		sti r1, %:live, %1
		and r1, %1, r1

 live:
		live %1
		zjmp %:live
