#pragma once

#include <vector>

#include "implementazione_grafo.hpp"
#include "contenitori.hpp"

template<typename Contenitore>
unidirected_graph graph_visit(const unidirected_graph& grafo, int nodo_sorgente, Contenitore& tipo_contenitore) {

    int n = grafo.all_nodes().size();
    std::vector<bool> reached(n);
    for (int i = 0; i < n; i++) {
        reached[i] = false;
    }
    unidirected_graph albero;
    tipo_contenitore.put(nodo_sorgente);
    reached[nodo_sorgente] = true;
    while (!tipo_contenitore.empty()) {
        int x = tipo_contenitore.get();
        for (int neighbour : grafo.neighbours(x)) {
            if (!reached[neighbour]) {
                reached[neighbour] = true;
                tipo_contenitore.put(neighbour);
                albero.add_edge(x, neighbour);
            }
        }
    }

    return albero;

}
