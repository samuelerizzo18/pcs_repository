#include <iostream>
#include <vector>
#include "partition.hpp"
#include "quicksort.hpp"
#include "insertion_sort_modificato.hpp"
#include "quicksort_modificato.hpp"

using namespace std;

template <typename T>
void print_vector(const vector<T>& A) {
    for (const auto& x : A)
        cout << x << " ";
    cout << endl;
}

int main() {
    int n = 60; //scelgo dimensione a caso
    vector<int> A(n);

    // riempi con numeri casuali tra -100 e 100
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 201 - 100;
    }

    cout << "Vettore originale:\n";
    print_vector(A);

    quicksort_modificato(A, 0, n - 1);

    cout << "\nVettore ordinato:\n";
    print_vector(A);

    return 0;
}