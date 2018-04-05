.name "HAZE"
.comment "DONT BE A FOOL"

start:
  sti r1, %:live, %1
  sti r1, %:breakdown, %2
  ld  %1, r1
  fork %:live
go:
    live %0
    ld %420, r2
    ld %420, r3
    zjmp %:breakdown
live:
	live %42
	zjmp %:live
breakdown:
	live %42
	st r2, -420
	st r2, -42
	st r2, -42
	st r2, 503
	st r2, -42
	st r2, -420
	st r2, -42
	st r2, -42
	st r2, 503
	st r2, -42
	zjmp %:breakdown
ld %420, r4
ld %240, r5
fork %:start
#fork %:go
zjmp %:live
