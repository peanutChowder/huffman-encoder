CC = g++
CC_FLAGS = -std=c++1z 

testSolution: encoding.o testSolution.cpp
	$(CC) $(CC_FLAGS) encoding.o testSolution.cpp -o testSolution


encoding.o: encoding.cpp encoding.h
	$(CC) $(CC_FLAGS) -c encoding.cpp -o encoding.o

clean:
	-rm *.o testSolution
