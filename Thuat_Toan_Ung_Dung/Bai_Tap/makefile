

testQuick: testQuick.o quick.o
	g++ testQuick.o quick.o -o testQuick
testQuick.o: testQuick.cpp quick.h 
	g++ -c testQuick.cpp

quick.o: quick.c quick.h
	g++ -c quick.c 

PohligHellman: PohligHellman.o mod.o
	g++ PohligHellman.o mod.o -o PohligHellman
PohligHellman.o: PohligHellman.cpp mod.h
	g++ -c PohligHellman.cpp

testMod: testMod.o mod.o
	g++ testMod.o mod.o -o testMod
testMod.o: testMod.cpp mod.h 
	g++ -c testMod.cpp

mod.o: mod.cpp mod.h
	g++ -c mod.cpp

UCLN: UCLN.o
	g++ UCLN.o -o UCLN
UCLN.o: UCLN.cpp
	g++ -c UCLN.cpp

clean:
	rm *.o