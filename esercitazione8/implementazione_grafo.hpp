#pragma once

#include <iostream>
#include <set>
#include <map>

class unidirected_edge {
    int nodo_partenza;
    int nodo_arrivo;

public:
    //definisco il costruttore della classe
    unidirected_edge(int n1, int n2) {
        if (n1 < n2) {
            nodo_partenza = n1;
            nodo_arrivo = n2;
        } else {
            nodo_partenza = n2;
            nodo_arrivo = n1;
        }
    };

    //metodo che restituisce nodo di partenza
    int from() const { 
        return nodo_partenza;
    };

    //metodo che restituisce nodo di arrivo
    int to() const { 
        return nodo_arrivo; 
    };

    //operatore di uguaglianza
    bool operator==(const unidirected_edge& other) const {
        return (nodo_partenza == other.nodo_partenza && nodo_arrivo == other.nodo_arrivo);
    }

    //operatore di ordinamento 
    bool operator<(const unidirected_edge& other) const {
        if (nodo_partenza < other.nodo_partenza) {
            return true;
        }

        if (nodo_partenza > other.nodo_partenza) {
            return false;
        }

        return nodo_arrivo < other.nodo_arrivo;
    }

    //operatore di output
    friend std::ostream& operator<<(std::ostream& os, const unidirected_edge& arco) {
        os << "(" << arco.from() << ", " << arco.to() << ")";
        return os;
    }

};

class unidirected_graph {
std::set<unidirected_edge> archi;
std::map<int, std::set<int>> lista_adiacenza;

public:
    //costruttore di default
    unidirected_graph() {};

    //costruttore di copia
    unidirected_graph(const unidirected_graph& other)         
        : archi(other.archi), lista_adiacenza(other.lista_adiacenza)
    {};

    //metodo neighbours
    std::set<int> neighbours(int nodo) const {
        if (lista_adiacenza.count(nodo) > 0) {
            return lista_adiacenza.at(nodo);
        }
        return {}; //restituisco un insieme vuoto se il nodo non è nella lista di adiacenza
    }

    //metodo add_edge
    void add_edge(int nodo1, int nodo2) {
        if (nodo1 == nodo2) {
            return; //esco dalla funzione per rispettare from < to
        }
        //aggiorno tutto
        unidirected_edge nuovo_arco(nodo1, nodo2);
        archi.insert(nuovo_arco);
        lista_adiacenza[nodo1].insert(nodo2);
        lista_adiacenza[nodo2].insert(nodo1);
    }

    //metodo all_edges
    std::set<unidirected_edge> all_edges() const {
        return archi; 
    }

    //metodo all_nodes()
    std::set<int> all_nodes() const {

        std::set<int> nodi;
        for (const auto& coppie_nodi : lista_adiacenza) {
            nodi.insert(coppie_nodi.first); //con .first si pesca la chiave, grazie alla quale possiamo accedere ai valori
                                            //è utile usare il set poiché elimina i duplicati
        }
        
        return nodi;
    }

    //metodo edge_number
    int edge_number(const unidirected_edge& arco) const {

    int indice = 0;
    for (const auto& edge : archi) {
        if (edge == arco) {
            return indice;
        }
        indice = indice + 1;
    }

    return -1; //se non trovo nulla faccio il return di -1
    }

    //metodo edge_at
    unidirected_edge edge_at(int numero_arco) const {

    int indice = 0;
    for (const auto& edge : archi) {
        if (indice == numero_arco) {
            return edge;
        }
        indice = indice + 1;
    }

    throw std::out_of_range("L'indice dell'arco non è valido: out of range");
    }

    //metodo operator-
    unidirected_graph operator-(const unidirected_graph& other) const {

    unidirected_graph differenza_grafi;

    for (const auto& arco : archi) {
        if (other.archi.count(arco) == 0) { //se arco non presente in G', lo aggiungo nella differenza (G-G')
            differenza_grafi.add_edge(arco.from(), arco.to()); //uso metodo implementato prima
        }
    }

    return differenza_grafi;
    }

};