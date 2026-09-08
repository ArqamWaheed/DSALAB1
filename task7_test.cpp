#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task7.h"
using namespace std;

int main() {
    int A[MAX][MAX] = {{1, 2}, {3, 4}};
    int B[MAX][MAX] = {{5, 6}, {7, 8}};
    int C[MAX][MAX], D[MAX][MAX];

    strassenMultiply(A, B, C, 2);
    naiveMultiply(A, B, D, 2);

    cout << "2x2 Strassen result:" << endl;
    printMatrix(C, 2);
    cout << "2x2 matches naive -> " << (sameMatrix(C, D, 2) ? "PASS" : "FAIL") << endl;
    cout << "C[0][0] == 19 -> " << (C[0][0] == 19 ? "PASS" : "FAIL") << endl << endl;

    int E[MAX][MAX] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int F[MAX][MAX] = {{2, 0, 1, 3}, {1, 1, 0, 2}, {4, 2, 3, 1}, {0, 5, 2, 1}};

    strassenMultiply(E, F, C, 4);
    naiveMultiply(E, F, D, 4);

    cout << "4x4 Strassen result:" << endl;
    printMatrix(C, 4);
    cout << "4x4 matches naive -> " << (sameMatrix(C, D, 4) ? "PASS" : "FAIL") << endl << endl;

    srand(time(0));
    bool ok = true;

    for (int test = 0; test < 5; test++) {
        int R1[MAX][MAX], R2[MAX][MAX];

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                R1[i][j] = rand() % 20;
                R2[i][j] = rand() % 20;
            }
        }

        strassenMultiply(R1, R2, C, 4);
        naiveMultiply(R1, R2, D, 4);

        if (!sameMatrix(C, D, 4)) ok = false;
    }

    cout << "5 random 4x4 tests match naive -> " << (ok ? "PASS" : "FAIL") << endl;

    return 0;
}
