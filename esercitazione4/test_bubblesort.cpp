#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>

#include "bubble_sort.h"
#include "is_sorted.h"
#include "randfiller.h"
#include "timecounter.h"

int main()
{
    randfiller rf;
    timecounter tc;

    //test sui 100
    for (int test = 0; test < 100; test++) {
        int n = rand() % 50 + 1;
        std::vector<int> v(n);
        rf.fill(v, -99, 99);

        bubble_sort(v);

        if (!is_sorted(v)) {
            std::cout << "Errore test casuale\n";
            return EXIT_FAILURE;
        } 
    }
    std::cout << "Successo dei 100\n";

    //vettore di STRINGHE
    std::vector<std::string> s = {"pcs", "edp", "database", "statistica", "fisica II", "equazioni e modelli fisica matematica", "inglese", "meccanica", "fisica I", "analisi I"};
    bubble_sort(s);
    if (!is_sorted(s)) {
            std::cout << "Tentativo stringhe fallito\n";
            return EXIT_FAILURE;
    } else {
       std::cout << "Successo vettore stringhe\n"; 
    }

    for (int n = 4; n <= 8192; n = n*2) {
        std::vector<int> v(n);
        rf.fill(v, -99, 99);
        std::vector<int> v_copia = v; //faccio una copia altriment l'algoritmo tratta un vettore già ordinato

        tc.tic();
        bubble_sort(v);
        double t1 = tc.toc();
        std::cout << "mio algortimo: " << t1 <<"\n";

        tc.tic();
        std::sort( v_copia.begin(), v_copia.end() );
        double t2 = tc.toc();
        std::cout << "algortimo già implementato: " << t2 <<"\n";

        if (!is_sorted(v)) {
            std::cout << "Tentativo numeri fallito\n";
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;

}