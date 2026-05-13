#pragma once

#include <vector>
#include <queue>

#include "implementazione_grafo.hpp"

unidirected_graph  dijkstra(const unidirected_graph& grafo, const std::vector<std::vector<int>>& W, int nodo_sorgente) {
    
    //vettore dei predecessori
    int n = grafo.all_nodes().size();
    std::vector<int> predecessori(n);
    for (int i = 0; i < n; i++) {
        predecessori[i] = -1;
    };

    //vettore delle distanze
    const int INF = 1e9;
    std::vector<int> distanza(n);
    for (int i = 0; i < n; i++) {
        distanza[i] = INF;
    }; 

    predecessori[nodo_sorgente] = nodo_sorgente;    
    distanza[nodo_sorgente] = 0;

    //definisco la coda con priorità
    std::priority_queue<std::pair<int,int>> pq;
    for(int i = 0; i < n; i++) {
        pq.push({-distanza[i], i}); //- davanti a distanza[i] per poter estrarre la distanza minore e non quella maggiore (perché la pq prende il max)
    };

    while(!pq.empty()) {
        int d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for (int w : grafo.neighbours(u)) {
            if (distanza[w] > distanza[u] + W[u][w]) {
                distanza[w] = distanza[u] + W[u][w];
                predecessori[w] = u;
                pq.push({-distanza[w], w}); //faccio l'update di w con la nuova distanza
            }
        }
    }

    //preparo albero cammini minimi
    unidirected_graph albero;

    //gli aggiungo gli archi
    for (int i = 0; i < n; i++) {
        if (predecessori[i] != -1 && predecessori[i] != i) {
            albero.add_edge(predecessori[i], i);
        }
    }

    return albero;
}