#pragma once
#include <iostream>
#include <vector>
#include "partition.hpp"

using namespace std;

template <typename T>
void quicksort(vector<T>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}