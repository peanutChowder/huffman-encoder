#include <vector>
#include <string>

#include "huffmanNode.h"

using namespace std;

void decodeArray(int *arr, HuffmanNode *root) {
    string encodedStr;
    vector<int> decoded;
    const HuffmanNode *currNode = root;

    for (char bit: encodedStr) {
        if (bit == '0') {
            currNode = currNode->left;
        } else if (bit == '1') {
            currNode = currNode->right;
        } else {
            perror("Invalid bit in decoding!! Aborting");
            exit(1);
        }

        if (currNode-> left == nullptr && currNode->right == nullptr) {
            decoded.push_back(currNode->val);
            currNode = root;
        }
    }
    
}