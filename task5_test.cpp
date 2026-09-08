#include <iostream>
#include "task5.h"
using namespace std;

int main() {
    int triangle[MAX_ROWS][MAX_ROWS];

    cout << "n = 0:" << endl;
    generatePascal(0, triangle);
    printPascal(0, triangle);
    cout << "nothing printed above -> PASS" << endl << endl;

    cout << "n = 1:" << endl;
    generatePascal(1, triangle);
    printPascal(1, triangle);
    cout << "triangle[0][0] == 1 -> " << (triangle[0][0] == 1 ? "PASS" : "FAIL") << endl << endl;

    cout << "n = 5:" << endl;
    generatePascal(5, triangle);
    printPascal(5, triangle);

    int expected[] = {1, 4, 6, 4, 1};
    bool ok = true;
    for (int j = 0; j < 5; j++) {
        if (triangle[4][j] != expected[j]) ok = false;
    }
    cout << "row 5 is {1, 4, 6, 4, 1} -> " << (ok ? "PASS" : "FAIL") << endl;

    return 0;
}
