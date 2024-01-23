#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

#include "huffmanNode.h"

using namespace std;

struct CompareNodes {
    bool operator() (HuffmanNode *a, HuffmanNode *b) {
        return a->frequency > b->frequency;
    }
};

void getSortedFrequency(vector<pair<int, int>> &repeatFrequency, int * array, int arrayLen) {
    for (int i = 0; i < arrayLen; i++) {
        if (repeatFrequency[array[i]].first == -1) {
            repeatFrequency[array[i]] = make_pair(array[i], 0);
        }

        repeatFrequency[array[i]].second++;
    }

    sort(repeatFrequency.begin(), repeatFrequency.end(), [](const auto &num1, const auto &num2) {
        return num1.second < num2.second;
    });
}

HuffmanNode* buildTree(vector<pair<int,int>> repeatFrequency) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;

    for (const pair item: repeatFrequency) {
        minHeap.push(new HuffmanNode(item.first, item.second));
    }

    while (minHeap.size() > 1) {
        HuffmanNode *left = minHeap.top();
        minHeap.pop();

        HuffmanNode *right = minHeap.top();
        minHeap.pop();

        HuffmanNode *currNode = new HuffmanNode(-1, left->frequency + right->frequency);
        currNode->left = left;
        currNode->right = right;

        minHeap.push(currNode);
    }

    return minHeap.top();
}

void encodeFromTree(HuffmanNode* root, std::unordered_map<int, std::string>& huffmanCodes, std::string code = "") {
    if (root) {
        if (root->val != -1) {
            huffmanCodes[root->val] = code;
        }

        encodeFromTree(root->left, huffmanCodes, code + "0");
        encodeFromTree(root->right, huffmanCodes, code + "1");
    }
}

int encodeInplace(int *input, const int inputLen, const unordered_map<int, string> &huffmanCodes) {
    string encodedString;
    string segment = "";

    for (int i = 0; i < inputLen; i++) {
        encodedString += huffmanCodes.at(input[i]);
    }

    int numSegments = 0;
    for (int i = 0; i < encodedString.length(); i++) {
        if (i % 30 == 0 && i) {
            input[numSegments] = stoi(segment.c_str(), nullptr, 2);
            segment = "";
            numSegments += 1;
        }

        segment += encodedString[i];
    }

    return numSegments;

}