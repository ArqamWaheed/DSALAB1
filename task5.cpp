#include <iostream>
#include "task5.h"
using namespace std;

void generatePascal(int n, int triangle[][MAX_ROWS]) {
    for (int i = 0; i < n; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
}

void printPascal(int n, int triangle[][MAX_ROWS]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}
