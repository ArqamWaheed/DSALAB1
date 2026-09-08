#include <iostream>
#include "task4.h"
using namespace std;

int main() {
    string text = "datastructures";

    int pos = findPattern(text, "data");
    cout << "Pattern at the beginning: " << pos << " -> " << (pos == 0 ? "PASS" : "FAIL") << endl;

    pos = findPattern(text, "tures");
    cout << "Pattern at the end: " << pos << " -> " << (pos == 9 ? "PASS" : "FAIL") << endl;

    pos = findPattern(text, "queue");
    cout << "Pattern not present: " << pos << " -> " << (pos == -1 ? "PASS" : "FAIL") << endl;

    pos = findPattern(text, "");
    cout << "Empty pattern: " << pos << " -> " << (pos == 0 ? "PASS" : "FAIL") << endl;

    pos = findPattern("abababc", "abc");
    cout << "First match only: " << pos << " -> " << (pos == 4 ? "PASS" : "FAIL") << endl;

    pos = findPattern("ab", "abcdef");
    cout << "Pattern longer than text: " << pos << " -> " << (pos == -1 ? "PASS" : "FAIL") << endl;

    return 0;
}
