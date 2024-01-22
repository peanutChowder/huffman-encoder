#include "encoding.h"

#include <vector>
#include <iostream>

using namespace std;

void byte_compress(int *data_ptr, int data_size) {
    vector<pair<int, int>> frequencies(128, make_pair(-1, -1));

    getSortedFrequency(frequencies, data_ptr, data_size);
    for (const auto freq: frequencies) {
        cout << freq.first << " " << freq.second << endl;
    }

}

void byte_decompress(int *data_ptr, int data_size) {

}

