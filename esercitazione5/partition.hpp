#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int partition(vector<T>& A, int p, int r) {
    T x = A[r];
    int i = p - 1;

    for (int j = p; j <= r-1; j++) {
        if (A[j] <= x) {
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1; //return del rango, ovvero della posizione del pivot nel vettore ordinato
}