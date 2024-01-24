CC = g++
CC_FLAGS = -std=c++1z 

testSolution: encoding.o decoding.o testSolution.cpp
	$(CC) $(CC_FLAGS) decoding.o encoding.o testSolution.cpp -o testSolution


encoding.o: encoding.cpp encoding.h
	$(CC) $(CC_FLAGS) -c encoding.cpp -o encoding.o

decoding.o: decoding.cpp decoding.h
	$(CC) $(CC_FLAGS) -c decoding.cpp -o decoding.o

clean:
	-rm *.o testSolution
