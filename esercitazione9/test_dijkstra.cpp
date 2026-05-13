#include <iostream>
#include <vector>

#include "implementazione_grafo.hpp"
#include "dijkstra.hpp"

int main() {

    //creo il grafo
    unidirected_graph g;

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(0, 4);

    g.add_edge(1, 2);

    g.add_edge(2, 3);

    g.add_edge(1, 4);
    g.add_edge(2, 4);
    g.add_edge(3, 4);

    //costruisco la matrice dei pesi
    const int INF = 1e9;

    std::vector<std::vector<int>> W = {

        //0      1      2      3      4
        {0,     5,     2,     3,     4},      // 0
        {5,     0,     INF,   INF,   1},      // 1
        {2,     INF,   0,     2,     1},      // 2
        {3,     INF,   1,     0,     2},      // 3
        {4,     1,     2,     2,     0}       // 4

    };


    int nodo_sorgente = 0;

    //eseguo dijkstra
    unidirected_graph albero_minimo = dijkstra(g, W, nodo_sorgente);

    //stampo gli archi dell'albero del cammino mimino
    std::cout << "Albero dei cammini minimi:\n";

    for (const auto& arco : albero_minimo.all_edges()) {
        std::cout << arco << std::endl;
    }

    return 0;
}