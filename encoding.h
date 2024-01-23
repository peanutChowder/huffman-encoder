#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct HuffmanNode;

void getSortedFrequency(vector<pair<int, int>> &repeatFrequency, int * array, int arrayLen);

HuffmanNode* buildTree(vector<pair<int,int>> repeatFrequency);

void encodeFromTree(HuffmanNode* root, unordered_map<int, std::string>& huffmanCodes, std::string code = "");

string getEncodedString(const int *input, const int inputLen, const unordered_map<int, string> &huffmanCodes);