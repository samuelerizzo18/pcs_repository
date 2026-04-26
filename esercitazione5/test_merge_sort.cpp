#include <iostream>
#include <vector>

#include "merge_sort.hpp"
#include "is_sorted.h"
#include "randfiller.h"

int main()
{
    randfiller rf;

    //test del merge_sort su 100 vettori di numeri
    for (int test = 0; test < 100; test++) {
        int n = rand() % 49 + 2; //dimensioni vettore (da 2 a 50)
        std::vector<int> v(n);
        rf.fill(v, -99, 99);

        merge_sort(v, 0, v.size() - 1);

        if (!is_sorted(v)) {
            std::cout << "Errore vettore numeri!\n";

            std::cout << "Vettore:\n";
            for (int x : v) {
                std::cout << x << " ";
            }
                std::cout << "\n";

        return EXIT_FAILURE;
        } 
    }

    std::cout << "Vettori dei numeri ordinati!\n";

    //test del merge_sort su un vettore di stringhe
    std::vector<std::string> s = {"pcs", "edp", "database", "statistica", "fisica II", "equazioni e modelli fisica matematica", "inglese", "meccanica", "fisica I", "analisi I"};

    merge_sort(s, 0, s.size() - 1);

    if (!is_sorted(s)) {
        std::cout << "Errore vettore stringhe!\n";
        return EXIT_FAILURE;
    } else {
       std::cout << "Vettore stringhe ordinato!\n"; 
    }


}