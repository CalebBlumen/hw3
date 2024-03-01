CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test 

llrec-test: llrec-test.cpp llrec.o llrec.h
	$(CXX) $(CXXFLAGS) llrec-test.cpp llrec.o -o llrec-test
	
llrec.o: llrec.h llrec.cpp
	$(CXX) $(CXXFLAGS) -c llrec.cpp -o llrec.o

clean:
	rm -f *.o rh llrec-test *~

valgrind: llrec-test
	$(VALGRIND) -v ./llrec-test llrec-test1.in

.PHONY: clean valgrind