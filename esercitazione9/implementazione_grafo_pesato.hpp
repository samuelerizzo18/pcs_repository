//è il copia e incolla di "implementazione_grafo.hpp" con l'aggiunta dei pesi

#pragma once

#include <set>
#include <map>
#include <vector>


class weighted_unidirected_edge {
int nodo_partenza;
int nodo_arrivo;
int peso;

public:
    //definisco il costruttore della classe
    weighted_unidirected_edge(int n1, int n2, int p) {

        if (n1 < n2) {
            nodo_partenza = n1;
            nodo_arrivo = n2;
        } else {
            nodo_partenza = n2;
            nodo_arrivo = n1;
        }

        peso = p;
    }

    //metodo che restituisce nodo di partenza
    int from() const {
        return nodo_partenza;
    }

    //metodo che restituisce nodo di arrivo
    int to() const {
        return nodo_arrivo;
    }

    //metodo che restituisce il peso
    int weight() const {
        return peso;
    }

    //operatore di uguaglianza
    bool operator==(const weighted_unidirected_edge& other) const {
        return (nodo_partenza == other.nodo_partenza && nodo_arrivo == other.nodo_arrivo && peso == other.peso);
    }

    // ordinamento
    bool operator<(const weighted_unidirected_edge& other) const {
        if (nodo_partenza < other.nodo_partenza) {
            return true;
        }

        if (nodo_partenza > other.nodo_partenza) {
            return false;
        }

        if (nodo_arrivo < other.nodo_arrivo) {
            return true;
        }

        if (nodo_arrivo > other.nodo_arrivo) {
            return false;
        }

        return peso < other.peso;
    }

    //operatore di output
    friend std::ostream& operator<<(std::ostream& os, const weighted_unidirected_edge& arco) {
        os << "(" << arco.from() << ", " << arco.to() << ", peso = " << arco.weight() << ")";
        return os;
    }
};


class weighted_unidirected_graph {
std::set<weighted_unidirected_edge> archi;
std::map<int, std::vector<std::pair<int,int>>> lista_adiacenza; // al nodo corrisponde la coppia (vicino,peso), ovvero: nodo -> [(vicino,peso)]

public:

    //costruttore di default
    weighted_unidirected_graph() {};

    //costruttore di copia
    weighted_unidirected_graph(const weighted_unidirected_graph& other)
        : archi(other.archi), lista_adiacenza(other.lista_adiacenza) {}

    //metodo neighbours
    std::vector<std::pair<int,int>> neighbours(int nodo) const {
        if (lista_adiacenza.count(nodo) > 0) {
            return lista_adiacenza.at(nodo);
        }
        return {};
    }

    //metodo add_edge
    void add_edge(int nodo1, int nodo2, int peso) {
        if (nodo1 == nodo2) {
            return;
        }
        //aggiorno tutto
        weighted_unidirected_edge nuovo_arco(nodo1, nodo2, peso);
        archi.insert(nuovo_arco);
        lista_adiacenza[nodo1].push_back({nodo2, peso});
        lista_adiacenza[nodo2].push_back({nodo1, peso});
    }

    //metodo all_edges
    std::set<weighted_unidirected_edge> all_edges() const {
        return archi;
    }

    //metodo all_nodes
    std::set<int> all_nodes() const {

        std::set<int> nodi;
        for (const auto& coppie_nodi : lista_adiacenza) {
            nodi.insert(coppie_nodi.first); //con .first si pesca la chiave, grazie alla quale possiamo accedere ai valori
                                            //è utile usare il set poiché elimina i duplicati
        }

        return nodi;
    }

};