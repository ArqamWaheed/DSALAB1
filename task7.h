#ifndef TASK7_H
#define TASK7_H

const int MAX = 8;

void addMatrix(int A[][MAX], int B[][MAX], int C[][MAX], int n);
void subMatrix(int A[][MAX], int B[][MAX], int C[][MAX], int n);
void naiveMultiply(int A[][MAX], int B[][MAX], int C[][MAX], int n);
void printMatrix(int A[][MAX], int n);
bool sameMatrix(int A[][MAX], int B[][MAX], int n);

#endif
