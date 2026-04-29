#pragma once
#include <vector>
#include <algorithm>

template <typename T>
void insertion_sort_modificato(vector<T>& A, int p, int r) {
    for (int i = p + 1; i <= r; i++) {
        T key = A[i];
        int j = i - 1;

        while (j >= p && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }

        A[j + 1] = key;
    }
}