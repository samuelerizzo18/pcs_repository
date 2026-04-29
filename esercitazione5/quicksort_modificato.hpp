#pragma once
#include <iostream>
#include <vector>
#include "partition.hpp"
#include "quicksort.hpp"
#include "insertion_sort_modificato.hpp"

using namespace std;

template <typename T>
void quicksort_modificato(vector<T>& A, int p, int r) {

    int soglia = 50;
    
    if (p < r){
        //sopra la soglia lavora quicksort
        if (r - p + 1 > soglia) {
            int q = partition(A, p, r);
            quicksort_modificato(A, p, q - 1);
            quicksort_modificato(A, q + 1, r);
        } else { 
            //sotto la soglia lavora insertion
            insertion_sort_modificato(A, p, r);
    }
    }

}