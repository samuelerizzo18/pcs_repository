#include <iostream>

#include "implementazione_grafo.hpp"
#include "contenitori.hpp"
#include "funzione_visita.hpp"

int main() {

    unidirected_graph g;

    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,3);
    g.add_edge(2,3);
    g.add_edge(1,4);

    //dfsG
    pila<int> s;
    unidirected_graph dfsG = graph_visit(g, 0, s);

    std::cout << "Albero DFS: " << std::endl;

    for (const auto& edge : dfsG.all_edges()) {
        std::cout << edge << std::endl;
    }

    std::cout << std::endl;

    //bfsG
    coda<int> q;
    unidirected_graph bfsG = graph_visit(g, 0, q);

    std::cout << "Albero BFS:" << std::endl;

    for (const auto& edge : bfsG.all_edges()) {
        std::cout << edge << std::endl;
    }

    return 0;
}