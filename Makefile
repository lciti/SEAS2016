

bandinverse.o: bandinverse.c
	gcc -c -o bandinverse.o bandinverse2.c

testbandinv.o: testbandinv.c
	gcc -c -o testbandinv.o testbandinv.c

testbandinv: testbandinv.o bandinverse.o
	gcc -o testbandinv testbandinv.o bandinverse.o
