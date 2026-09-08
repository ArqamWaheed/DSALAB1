#include "task3.h"

int findAllIndices(int arr[], int n, int key, int indices[]) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            indices[count] = i;
            count++;
        }
    }

    return count;
}
