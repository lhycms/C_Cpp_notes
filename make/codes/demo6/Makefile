### 生成动态链接库，然后运行程序

all : run

# 运行程序
run : main
	./main 12 23

# 生成可执行文件
main : main.o libfunctions.so
	g++ -Wall main.o -L. -lfunctions -o main

# 生成动态链接库
libfunctions.so : functions.o
	g++ -Wall -shared functions.o -o libfunctions.so

# 生成 `共享目标文件`
functions.o : functions.cpp 
	g++ -Wall -fpic -c functions.cpp -o functions.o

# 清除编译产生的所有文件（目标文件、可执行文件、动态链接库）
.PHONY: clean
clean:
	rm *.o *.so main