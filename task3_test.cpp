#include <iostream>
#include "task3.h"
using namespace std;

void printIndices(int indices[], int count) {
    cout << "{";
    for (int i = 0; i < count; i++) {
        cout << indices[i] << (i == count - 1 ? "" : ", ");
    }
    cout << "}";
}

int main() {
    int indices[50];

    int a[] = {5, 2, 5, 7, 5, 1};
    int count = findAllIndices(a, 6, 5, indices);
    cout << "Multiple occurrences: ";
    printIndices(indices, count);
    cout << " -> " << (count == 3 && indices[0] == 0 && indices[1] == 2 && indices[2] == 4 ? "PASS" : "FAIL") << endl;

    int b[] = {1, 2, 3, 4};
    count = findAllIndices(b, 4, 9, indices);
    cout << "Key not present: count = " << count << " -> " << (count == 0 ? "PASS" : "FAIL") << endl;

    int c[1];
    count = findAllIndices(c, 0, 5, indices);
    cout << "Empty array: count = " << count << " -> " << (count == 0 ? "PASS" : "FAIL") << endl;

    return 0;
}
