#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct HuffmanNode {
    int val;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(int val, int frequency): val(val), frequency(frequency), left(nullptr), right(nullptr) {}
};

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