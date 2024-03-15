
.PHONY: install clean all

all:	calc cat charch collatz echo ex hq9p listis ls multiply random tar texor wc touch minian pkgm memory clear timer
	echo 'Done!'

calc:	calc.c
	cc -o calc calc.c
cat:	cat.c
	cc -o cat cat.c
charch:	charch.c
	cc -o charch charch.c
collatz: collatz.c 
	cc -o collatz collatz.c
echo:	echo.c 
	cc -o echo echo.c
ex:		ex.c
	cc -o ex ex.c
hq9p:	hq9p.c
	cc -o hq9p hq9p.c
listis: listis.c
	cc -o listis listis.c
ls:		ls.c
	cc -o ls ls.c
multiply: multiply.c
	cc -o multiply multiply.c
random: random.c
	cc -o random random.c
tar:	tar.c
	cc -o tar tar.c
texor:	texor.c
	cc -o texor texor.c
wc:		wc.c
	echo 'WC?! Hahahahahahahahahahahahah'
	cc -o wc wc.c
touch:	touch.c
	cc -o touch touch.c
minian:	minian.c
	cc -o minian minian.c
pkgm:	pkgm.c
	cc -o pkgm pkgm.c
clear:	clear.c
	cc clear.c -o clear
memory:	games/memory.c
	cc games/memory.c -o memory
timer:
	cc timer.c -o timer


install:	calc cat charch collatz echo ex hq9p listis ls multiply random tar texor wc touch minian pkgm clear memory timer
	mv calc cat charch collatz echo ex hq9p listis ls multiply random tar texor wc touch minian pkgm clear ../../usr/bin/
	mv memory ../../usr/bin/games/memory
	mv timer ../../usr/bin/timer

clean:
	rm -f ../../usr/bin/calc ../../usr/bin/cat ../../usr/bin/charch ../../usr/bin/collatz ../../usr/bin/echo ../../usr/bin/ex ../../usr/bin/hq9p ../../usr/bin/listis ../../usr/bin/ls ../../usr/bin/multiply ../../usr/bin/random ../../usr/bin/tar ../../usr/bin/texor ../../usr/bin/wc ../../usr/bin/touch ../../usr/bin/minian ../../usr/bin/pkgm ../../usr/bin/clear ../../usr/bin/games/memory ../../usr/bin/timer
