### 使用 `implicit rules` 中的 `variables` 进行编译
CXX := g++
CXXFLAGS := -Og -Wall -c
LDFLAGS := -L.
LDLIBS := -lfunctions


all : main
	./main 12 23 

main : main.o libfunctions.so
	$(CXX) -Og -Wall main.o $(LDFLAGS) $(LDLIBS) -o $@

main.o : main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

libfunctions.so : functions.o
	$(CXX) -Wall -shared $< -o $@

functions.o : functions.cpp
	$(CXX) $(CXXFLAGS) $< -o $@


.PHONY: clean
clean:
	rm *.o *so main