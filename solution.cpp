#include "encoding.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

string byte_compress(int *data_ptr, int data_size) {
    vector<pair<int, int>> frequencies(128, make_pair(-1, -1));

    unordered_map<int, string> huffmanCodes;

    getSortedFrequency(frequencies, data_ptr, data_size / sizeof(data_ptr[0]));

    HuffmanNode *root = buildTree(frequencies);
    encodeFromTree(root, huffmanCodes);
    string encodedStr = getEncodedString(data_ptr, data_size / sizeof(data_ptr[0]), huffmanCodes);

    return encodedStr;
}

void byte_decompress(int *data_ptr, int data_size) {

}

