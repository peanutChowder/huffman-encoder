#include <vector>
#include <algorithm>
#include <string>

#include "huffmanNode.h"
using namespace std;

pair<int, HuffmanNode*> byte_compress(int *data_ptr, int data_size);

void getSortedFrequency(vector<pair<int, int>> &repeatFrequency, int * array, int arrayLen);

HuffmanNode* buildTree(vector<pair<int,int>> repeatFrequency);

void encodeFromTree(HuffmanNode* root, unordered_map<int, std::string>& huffmanCodes, std::string code = "");

int encodeInplace(int *input, const int inputLen, const unordered_map<int, string> &huffmanCodes);