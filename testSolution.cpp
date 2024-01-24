#include "encoding.h"

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

void printCompressionStats(int * data, int dataLen, string dataName) {
    cout << dataName << endl;
    cout << "size: " << sizeof(data[0]) * dataLen << " bytes." << endl;
    cout << "[ ";
    for (int i = 0; i < dataLen; i++) {
        cout << data[i] << ", ";
    }
    cout << "]" << endl;
    cout << "-----------------" << endl;
}

int main() {
    int testData[] = {101, 125, 87, 115, 48, 93, 97, 64, 76, 109, 31, 53, 111, 100, 92, 36, 8, 60, 88, 115, 19, 18, 123, 119, 62, 118, 8, 49, 10, 40, 17, 14, 121, 109, 76, 19, 62, 30, 15, 46, 68, 11, 121, 13, 103, 56, 41, 77, 87, 104, 11, 37, 127, 52, 39, 16, 81, 118, 53, 24, 97, 97, 108, 109, 118, 90, 104, 56, 48, 94, 26, 94, 87, 93, 14, 98, 103, 72, 100, 81, 114, 105, 92, 97, 66, 114, 65, 107, 64, 0, 122, 59, 6, 67, 38, 44, 39, 34, 114, 74};
    pair<int, HuffmanNode*> returnVal;

    // Print original array data and size
    printCompressionStats(testData, sizeof(testData) / sizeof(testData[0]), "Original data");
    returnVal = byte_compress(testData, sizeof(testData));

    // Print compressed data and size
    printCompressionStats(testData, returnVal.first / sizeof(testData[0]), "Compressed Data");
    
    return 0;
}