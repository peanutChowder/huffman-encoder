using namespace std;

void getFrequency(int *repeatFrequency, int * array, int arrayLen) {
    for (int i = 0; i < arrayLen; i++) {
        repeatFrequency[array[i]]++;
    }
}