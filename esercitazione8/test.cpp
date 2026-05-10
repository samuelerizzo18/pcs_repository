#include <iostream>
#include <set>
#include <map>

#include "implementazione_grafo.hpp"

int main() {

    //costruttore di default
    unidirected_graph g;

    g.add_edge(1, 4);
    g.add_edge(1, 9);

    //costruttore di copia
    unidirected_graph copia_grafo(g);


    //metodo neighbours
    std::cout << "Vicini del nodo 1: ";

    for (const auto& vicino : g.neighbours(1)) {
        std::cout << vicino << " ";
    }
    std::cout << "\n";
    std::cout << "\n";


    //metodo add_edge
    g.add_edge(2, 4);
    g.add_edge(3, 7);


    //metodo all_edges
    std::cout << "Stampa di tutti gli archi: ";
    for (const auto& arco : g.all_edges()) {
        std::cout << arco <<" ";
    }
    std::cout << "\n";
    std::cout << "\n";


    //metodo all_nodes
    std::cout << "Stampa di tutti i nodi: ";
    for (const auto& nodo : g.all_nodes()) {
        std::cout << nodo << " ";
    }
    std::cout << "\n";
    std::cout << "\n";


    //metodo edge_number
    unidirected_edge e(1, 5);
    std::cout << "Numero dell'arco " << e << " : " << g.edge_number(e) << "\n";


    //metodo edge_at
    std::cout << "Arco in posizione 2: " << g.edge_at(2);
    std::cout << "\n";
    std::cout << "\n";


    //metodo operator-
    unidirected_graph g_primo;

    g_primo.add_edge(1, 4);
    g_primo.add_edge(3, 7);

    unidirected_graph differenza = g - g_primo;

    std::cout << "G - G': ";
    for (const auto& arco : differenza.all_edges()) {
        std::cout << arco << " ";
    }
    std::cout << "\n";

    //fine main
    return 0;
}