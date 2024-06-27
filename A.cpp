#include <iostream>
using namespace std;
class CountSort {
private:
    int* org_arr;
    int* output_arr;
public:
    CountSort() {
        org_arr = NULL;
        output_arr = NULL;
    }
    ~CountSort() {
        delete[] org_arr;
        delete[] output_arr;
    }
    void read_inputs(int* n);
    void countSort();
    void printArr();
};
void CountSort::read_inputs(int* n) {
    org_arr = new int[*n];
    for (int i = 0; i < *n; i++) {
        std::cin >> org_arr[i];
    }
}
void CountSort::countSort() {
    int size = sizeof(org_arr) / sizeof(org_arr[0]);
    int max = 0; int index = 0;
    //int num  = size + 1;
    if (size % 2 != 0) {
        max = org_arr[0];
        index += 1;
    }
    else {
        if (org_arr[0] < org_arr[1]) {
            max = org_arr[1];
        }
        else {
            max = org_arr[0];
        }
        index += 2;
    }
    for (int i = 0; i < size - 1; i = i + 2) {
        int big;
        if (org_arr[i] < org_arr[i + 1]) {
            big = org_arr[i + 1];
        }
        else {
            big = org_arr[i];
        }
        if (max < big) {
            max = big;
        }
    }
    int* count = new int[max + 1];
    for (int j = 0; j < size; j++) {
        count[org_arr[j]]++;
    }
    for (int ix = 0; ix < max; ix++) {
        count[ix + 1] += count[ix];
    }
    output_arr =  new int[size];
    for (int jx = size - 1; jx >= 0; jx--) {
        output_arr[count[org_arr[jx]] - 1] = org_arr[jx];
        count[org_arr[jx]]--;
    }
    delete[] count;
}
void Countsort::printArr() {
    //int size = sizeof(output_arr) / sizeof(output_arr[0]);
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            cout << output_arr[i] << endl;
        }
        else cout << output_arr[i] << " ";
    }
}
int main() {
    CountSort countingSort; int n;
    cin >> n;
    countingSort.read_inputs(&n);
    countingSort.countSort();
    countingSort.printArr();
    return 0;
}
