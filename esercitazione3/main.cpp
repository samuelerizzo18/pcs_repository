#include <iostream>
#include "implementazione_rational.hpp"

int main() {
    int n1; 
    int d1;
    int n2;
    int d2;

    std::cout << "Inserisci numeratore e denominatore del primo razionale: ";
    std::cin >> n1 >> d1;

    std::cout << "Inserisci numeratore e denominatore del secondo razionale: ";
    std::cin >> n2 >> d2;

    rational<int> r1(n1, d1);
    rational<int> r2(n2, d2);

    std::cout << "r1 = " << r1 << "\n";
    std::cout << "r2 = " << r2 << "\n";

    std::cout << "Operazioni\n";

    std::cout << "Somma: " << (r1 + r2) << "\n";
    std::cout << "Differenza: " << (r1 - r2) << "\n";
    std::cout << "Prodotto: " << (r1 * r2) << "\n";
    std::cout << "Rapporto: " << (r1 / r2) << "\n";

    return 0;
}