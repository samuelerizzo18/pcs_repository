#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "quicksort_modificato.hpp"   // il tuo quick ibrido
#include "quicksort.hpp"              // quicksort normale
#include "timecounter.h"              // tic/toc

using namespace std;

// riempie vettore con valori casuali
void fill_random(vector<int>& v, int min, int max) {
    for (auto& x : v) {
        x = rand() % (max - min + 1) + min;
    }
}

int main() {

    srand(time(NULL));

    timecounter tc;

    int num_test = 1000;  // aumenta per misure migliori

    cout << "Dim\tQuick\tQuick_mod\n";

    for (int n = 10; n <= 100; n += 10) {

        // 🔹 dataset
        vector<vector<int>> datasets(num_test, vector<int>(n));
        for (auto& v : datasets) {
            fill_random(v, -100, 100);
        }

        // 🔹 quicksort normale
        tc.tic();
        for (auto v : datasets) {
            vector<int> temp = v;
            quicksort(temp, 0, temp.size() - 1);
        }
        double t_quick = tc.toc() / num_test;

        // 🔹 quicksort modificato
        tc.tic();
        for (auto v : datasets) {
            vector<int> temp = v;
            quicksort_modificato(temp, 0, temp.size() - 1);
        }
        double t_quick_mod = tc.toc() / num_test;

        // 🔹 stampa
        cout << n << "\t"
             << t_quick << "\t"
             << t_quick_mod << "\n";
    }

    return 0;
}