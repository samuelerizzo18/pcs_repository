#pragma once

#include <vector>

#include "implementazione_grafo.hpp"

//funzione ricorsiva ausiliaria 
void visita_ricorsiva(const unidirected_graph& grafo, int x, std::vector<bool>& reached, unidirected_graph& albero) {

    reached[x] = true;

    for (int neighbour : grafo.neighbours(x)) {
        if (!reached[neighbour]) {
            albero.add_edge(x, neighbour);
            visita_ricorsiva(grafo, neighbour, reached, albero);
        }
    }
}


//funzione recursive dfs
unidirected_graph recursive_dfs(const unidirected_graph& grafo, int nodo_sorgente) {

    //definisco il vettore reached (indica se un nodo è stato visitato oppure no)
    int n = grafo.all_nodes().size();
    std::vector<bool> reached(n);
    for (int i = 0; i < n; i++) {
        reached[i] = false;
    }

    //definisco albero
    unidirected_graph albero;

    //funzione ricorsiva ausiliaria
    visita_ricorsiva(grafo, nodo_sorgente, reached, albero);

    return albero;
}