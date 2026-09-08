#include <iostream>
#include "task6.h"
using namespace std;

int main() {
    int a[] = {4, 1, 4, 7, 4, 1};
    int mode = findMode(a, 6);
    cout << "Unique mode: " << mode << " -> " << (mode == 4 ? "PASS" : "FAIL") << endl;
    cout << "It occurs " << countOf(a, 6, 4) << " times -> " << (countOf(a, 6, 4) == 3 ? "PASS" : "FAIL") << endl;

    int b[] = {2, 2, 5, 5, 9};
    mode = findMode(b, 5);
    cout << "Multiple modes, first one wins: " << mode << " -> " << (mode == 2 ? "PASS" : "FAIL") << endl;

    int c[] = {8};
    mode = findMode(c, 1);
    cout << "Single element: " << mode << " -> " << (mode == 8 ? "PASS" : "FAIL") << endl;

    int d[1];
    mode = findMode(d, 0);
    cout << "Empty array: " << mode << " -> " << (mode == -1 ? "PASS" : "FAIL") << endl;

    return 0;
}
