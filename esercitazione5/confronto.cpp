#include <iostream>
#include <vector>
#include <algorithm>

#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "merge_sort.hpp"
#include "quicksort.hpp"
#include "is_sorted.h"
#include "randfiller.h"
#include "timecounter.h"

int main() {

    randfiller rf;
    timecounter tc;
    int numero_vettori = 100;

    //stampo le colonne
    cout << "Dim\tBubble\tInsertion\tSelection\tMerge\tQuick\tSort\n";

    for (int n = 10; n <= 100; n += 10) {

        //creo dataset
        vector<vector<int>> datasets(numero_vettori, vector<int>(n));

        for (auto& v : datasets) {
            rf.fill(v, -99, 99);
        }

        //bubble
        tc.tic();
        for (auto v : datasets) {
            vector<int> vettore = v;
            bubble_sort(vettore);
        }
        double t1 = tc.toc() / numero_vettori;

        //insertion
        tc.tic();
        for (auto v : datasets) {
            vector<int> vettore = v;
            insertion_sort(vettore);
        }
        double t2 = tc.toc() / numero_vettori;

        //selection
        tc.tic();
        for (auto v : datasets) {
            vector<int> vettore = v;
            selection_sort(vettore);
        }
        double t3 = tc.toc() / numero_vettori;

        //merge
        tc.tic();
        for (auto v : datasets) {
            vector<int> vettore = v;
            merge_sort(vettore, 0, vettore.size() - 1);
        }
        double t4 = tc.toc() / numero_vettori;

        //quick
        tc.tic();
        for (auto v : datasets) {
            vector<int> vettore = v;
            quicksort(vettore, 0, vettore.size() - 1);
        }
        double t5 = tc.toc() / numero_vettori;

        //sort
        tc.tic();
        for (auto v : datasets) {
            vector<int> vettore = v;
            sort(vettore.begin(), vettore.end());
        }
        double t6 = tc.toc() / numero_vettori;

        //stampo le righe
        cout << n << "\t"
             << t1 << "\t"
             << t2 << "\t"
             << t3 << "\t"
             << t4 << "\t"
             << t5 << "\t"
             << t6 << "\n";
    }

}
