#include "task6.h"

int countOf(int arr[], int n, int key) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) count++;
    }

    return count;
}

int findMode(int arr[], int n) {
    if (n == 0) return -1;

    int mode = arr[0];
    int highest = 0;

    for (int i = 0; i < n; i++) {
        int freq = countOf(arr, n, arr[i]);
        if (freq > highest) {
            highest = freq;
            mode = arr[i];
        }
    }

    return mode;
}
