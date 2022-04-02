all : main

main : main.o libfunction.a(libadd.a libsubstract.a)
	g++ -Wall -std=c++17 main.o -L. -lfunction -o main

libfunction.a(libadd.a libsubstract.a) : libadd.a libfunction.a
	ar rcs libfunction.a libadd.a libsubstract.a

libadd.a : add.o
	ar rcs libadd.a add.o

libsubstract.a : substract.o
	ar rcs libsubstract.a substract.o

add.o : add.cpp
	g++ -Wall -std=c++17 -c add.cpp -o add.o

substract.o : substract.cpp
	g++ -Wall -std=c++17 -c substract.cpp -o substract.o

.PHONY: clean
clean:
	rm -r *.o *.a main