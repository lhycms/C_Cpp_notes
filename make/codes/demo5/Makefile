### 生成静态库，然后运行程序

all : run 

# 运行可执行文件
run : main
	./main 12 23

# 生成可执行文件
main : main.o libfunctions.a(functions.o)
	g++ -Wall main.o -L. -lfunctions -o main

# 生成静态库
libfunctions.a(functions.o) : functions.o
	ar rcs libfunctions.a functions.o

functions.o : functions.cpp
	g++ -Wall -c functions.cpp -o functions.o 

# 清除编译产生的所有文件
.PHONY:clean
clean:
	rm *.o main