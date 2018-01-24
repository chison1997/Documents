quickSort.o: quickSort.c quickSort.h
	gcc -c quickSort.c
Sort.o: Sort.c
	gcc -c Sort.c
Sort: Sort.o quickSort.o
	gcc Sort.o quickSort.o -o Sort
	
SortMultiThread.o: SortMultiThread.c
	gcc -c SortMultiThread.c
SortMultiThread: SortMultiThread.o quickSort.o
	gcc SortMultiThread.o quickSort.o -lpthread -o  SortMultiThread

gen.o: gen.c
	gcc -c gen.c
gen: gen.o
	gcc gen.o -o gen