#include <iostream>
#include "task7.h"
using namespace std;

void addMatrix(int A[][MAX], int B[][MAX], int C[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subMatrix(int A[][MAX], int B[][MAX], int C[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void naiveMultiply(int A[][MAX], int B[][MAX], int C[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void strassenMultiply(int A[][MAX], int B[][MAX], int C[][MAX], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int a11[MAX][MAX], a12[MAX][MAX], a21[MAX][MAX], a22[MAX][MAX];
    int b11[MAX][MAX], b12[MAX][MAX], b21[MAX][MAX], b22[MAX][MAX];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j+k];
            a21[i][j] = A[i+k][j];
            a22[i][j] = A[i+k][j+k];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j+k];
            b21[i][j] = B[i+k][j];
            b22[i][j] = B[i+k][j+k];
        }
    }

    int p1[MAX][MAX], p2[MAX][MAX], p3[MAX][MAX], p4[MAX][MAX];
    int p5[MAX][MAX], p6[MAX][MAX], p7[MAX][MAX];
    int t1[MAX][MAX], t2[MAX][MAX];

    addMatrix(a11, a22, t1, k);
    addMatrix(b11, b22, t2, k);
    strassenMultiply(t1, t2, p1, k);

    addMatrix(a21, a22, t1, k);
    strassenMultiply(t1, b11, p2, k);

    subMatrix(b12, b22, t1, k);
    strassenMultiply(a11, t1, p3, k);

    subMatrix(b21, b11, t1, k);
    strassenMultiply(a22, t1, p4, k);

    addMatrix(a11, a12, t1, k);
    strassenMultiply(t1, b22, p5, k);

    subMatrix(a21, a11, t1, k);
    addMatrix(b11, b12, t2, k);
    strassenMultiply(t1, t2, p6, k);

    subMatrix(a12, a22, t1, k);
    addMatrix(b21, b22, t2, k);
    strassenMultiply(t1, t2, p7, k);

    int c11[MAX][MAX], c12[MAX][MAX], c21[MAX][MAX], c22[MAX][MAX];

    addMatrix(p1, p4, t1, k);
    subMatrix(t1, p5, t2, k);
    addMatrix(t2, p7, c11, k);

    addMatrix(p3, p5, c12, k);
    addMatrix(p2, p4, c21, k);

    addMatrix(p1, p3, t1, k);
    subMatrix(t1, p2, t2, k);
    addMatrix(t2, p6, c22, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = c11[i][j];
            C[i][j+k] = c12[i][j];
            C[i+k][j] = c21[i][j];
            C[i+k][j+k] = c22[i][j];
        }
    }
}

void printMatrix(int A[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}

bool sameMatrix(int A[][MAX], int B[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != B[i][j]) return false;
        }
    }

    return true;
}
