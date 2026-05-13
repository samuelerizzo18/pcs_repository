#pragma once

#include <queue>
#include <stack>

//contenitore con politica FIFO
template<typename T>
class coda {
    std::queue<T> q; //queue

public:
    //costruttore di default
    coda() {};

    //metodo put
    void put(const T& nodo) {
        q.push(nodo);
    };

    //metodo get
    T get() {
        T x = q.front();  //salvo l'elemento
        q.pop();          //e poi lo rimuovo
        return x;
    };

    //metodo empty
    bool empty() {
        return q.empty();
    };
};

//contenitore con politica LIFO
template<typename T>
class pila {
    std::stack<T> s; //stack
    
public:
    //costruttore di default
    pila() {};

    //metodo put
    void put(const T& nodo) {
        s.push(nodo);
    };

    //metodo get
    T get() {
        T x = s.top();   //salvo l'elemento
        s.pop();          //e poi lo rimuovo
        return x;
    };

    //metodo empty
    bool empty() {
        return s.empty();
    };

};