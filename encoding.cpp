#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

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