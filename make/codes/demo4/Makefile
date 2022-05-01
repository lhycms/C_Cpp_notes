all : test1.o test2.o

# 匹配rule：可以生成 test1.o, test2.o
%.o : %.cpp
	g++ -Wall -c $< -o $@

test1.cpp test2.cpp :
	echo "int main() {return 0;}" > $@

.PHONY: clean
clean: 
	rm *.cpp *.o