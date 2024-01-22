CC = g++
CC_FLAGS = -std=c++1z 

testSolution: encoding.o solution.o testSolution.cpp
	$(CC) $(CC_FLAGS) encoding.o testSolution.cpp solution.o -o testSolution

solution.o: solution.cpp solution.h
	$(CC) $(CC_FLAGS) -c solution.cpp -o solution.o

encoding.o: encoding.cpp encoding.h
	$(CC) $(CC_FLAGS) -c encoding.cpp -o encoding.o

clean:
	-rm *.o testSolution
