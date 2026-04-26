#pragma once
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

//sarebbe la funzione fusion
template <typename T>
void merge(vector<T>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    //creo i vettori
    vector<T> L(n1 + 1); //per la parte di sinistra rispetto al centro q
    vector<T> R(n2 + 1); //per la parte di destra rispetto al centro q

    //copio in L
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }

    //copio in R
    for (int j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }

    //ricostruisco il vettore A ordinato, partendo dai vettori L e R già ordinati: ogni volta prendo il più piccolo tra i due vettori e lo inserisco in A
    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }

    //qui ho finito di completare R ma rimane ancora libero L
    while (i < n1) {
        A[k++] = L[i++];
    }

    //qui ho finito di completare L ma rimane ancora libero R
    while (j < n2) {
        A[k++] = R[j++];
    }

}