CC = g++
CC_FLAGS = -std=c++1z 

testSolution: solution.o testSolution.cpp
	$(CC) $(CC_FLAGS) testSolution.cpp solution.o -o testSolution

solution.o: solution.cpp solution.h
	$(CC) $(CC_FLAGS) -c solution.cpp -o solution.o

clean:
	-rm *.o testSolution
