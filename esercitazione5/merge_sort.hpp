#pragma once
#include <iostream>
#include <vector>
#include "merge.hpp"

using namespace std;

template <typename T>
void merge_sort(vector<T>& A, int p, int r) {
    if (p < r) {
        int q = ((p + r)/2);
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}