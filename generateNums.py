"""
Use this to generate an n-length array of integers for test input.
Copy paste output from program output to C++ array initializer.
"""
import random

NUM_ENTRIES = 100

print("{", end="")
for i in range(NUM_ENTRIES):
    if i + 1 < NUM_ENTRIES:
        print(random.randint(0, 127), end=", ")
        continue
    
    print(random.randint(0, 127), end="")

print("}")