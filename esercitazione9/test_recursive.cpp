#include <iostream>

#include "implementazione_grafo.hpp"
#include "funzione_recursive_dfs.hpp"


int main() {

    //creo il grafo
    unidirected_graph g;

    //aggiungo archi
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,3);
    g.add_edge(2,3);
    g.add_edge(1,4);

    //eseguo DFS ricorsiva
    unidirected_graph albero = recursive_dfs(g, 0);

    //stampo gli archi dell'albero DFS
    std::cout << "Albero DFS ricorsivo:" << std::endl;

    for (auto edge : albero.all_edges()) {
        std::cout << "(" << edge.from() << ", " << edge.to() << ")" << std::endl;
    }

    return 0;
}