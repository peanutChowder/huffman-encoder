#include "encoding.h"

#include <map>
#include <iostream>

using namespace std;

void byte_compress(int *data_ptr, int data_size) {
    int frequencies[128] = { 0 };

    getFrequency(frequencies, data_ptr, data_size);

}

void byte_decompress(int *data_ptr, int data_size) {

}

