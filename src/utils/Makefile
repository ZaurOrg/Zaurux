#   Copyright 2024 AnatoliyL
#   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
#   1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer
#   2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
#   3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
#   4. All products derived from this software must retain permittion to redistribute, use in source and binary forms, with or without modification.
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
.PHONY: install clean all

all:	calc cat charch collatz echo ex hq9p listis ls multiply random tar texor wc touch minian pkgm
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


install:	calc cat charch collatz echo ex hq9p listis ls multiply random tar texor wc touch minian pkgm
	mv calc cat charch collatz echo ex hq9p listis ls multiply random tar texor wc touch minian pkgm ../../bin/

clean:
	rm -f ../../bin/calc ../../bin/cat ../../bin/charch ../../bin/collatz ../../bin/echo ../../bin/ex ../../bin/hq9p ../../bin/listis ../../bin/ls ../../bin/multiply ../../bin/random ../../bin/tar ../../bin/texor ../../bin/wc ../../bin/touch