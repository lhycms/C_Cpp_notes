all : main

main : main.o libfunction.a(add.o substract.o)
	g++ -Wall -std=c++17 main.o -L. -lfunction -o main

libfunction.a(add.o substract.o) : add.o substract.o
	ar rcs libfunction.a add.o substract.o

add.o : add.cpp
	g++ -Wall -std=c++17 -c add.cpp -o add.o

substract.o : substract.cpp
	g++ -Wall -std=c++17 -c substract.cpp -o substract.o

.PHONY: clean
clean:
	rm -r *.o *.a main