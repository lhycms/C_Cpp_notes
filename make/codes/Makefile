# Define Variables
OBJECTS = main.o function1.o function2.o

# Default Goal
main : $(OBJECTS)
	g++ -Wall $(OBJECTS) -o main

function1.o : function1.cpp functions.h
	g++ -Wall -c function1.cpp -o function1.o

function2.o : function2.cpp functions.h
	g++ -Wall -c function2.cpp -o function2.o

main.o : main.cpp functions.h
	g++ -Wall -c main.cpp -o main.o

# 当文件夹中出现 clean 文件
.PHONY : clean
clean : 
	rm $(OBJECTS) main