MaxSubSeq.o: MaxSubSeq.cpp
	g++ -c MaxSubSeq.cpp
MaxSubSeq: MaxSubSeq.o
	g++ MaxSubSeq.o -o MaxSubSeq
taoDay.o: taoDay.cpp
	g++ -c taoDay.cpp
taoDay: taoDay.o
	g++ taoDay.o -o taoDay
seq10.txt: taoDay
	./taoDay 10 seq10.txt
seq100.txt: taoDay
	./taoDay 100 seq100.txt
seq1000.txt: taoDay
	./taoDay 1000 seq1000.txt
seq10000.txt: taoDay
	./taoDay 10000 seq10000.txt
seq100000.txt: taoDay
	./taoDay 100000 seq100000.txt

