#include <map>

using namespace std;

void frequencyArr(map<int, int> frequencyMap, int * array, int arrayLen) {
    for (int i = 0; i < arrayLen; i++) {
        frequencyMap[array[i]]++;
    }
}