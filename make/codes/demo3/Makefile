CXX = g++
CXXFLAGS = -Wall -std=c++17


main : main.o function.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

function.o : function.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm -r *.o *.a main