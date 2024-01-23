struct HuffmanNode {
    int val;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(int val, int frequency): val(val), frequency(frequency), left(nullptr), right(nullptr) {}
};