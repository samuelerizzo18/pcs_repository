#pragma once    //serve per includere sono una volta questo file .hpp (si evita ridefinizione)

#include <iostream>
#include <concepts>
#include <numeric>

template<typename I> requires std::integral<I>  //classe template parametrizzata da un tipo I, il quale deve essere un intero (in questo caso)
class rational {    //dichiaro all'interno della classe rational due interi: numeratore e denominatore
    I num_;
    I den_;

public:
    /* Costruttore di default */
    rational()
        : num_(I{0}), den_(I{1})    //inizializzo il numeratore e denominatore rispettivamente a 0 e 1, e lo faccio in riferimento al template I
    {}

    /* Costruttore user-defined */
    rational(const I& pnum, const I& pden)
        : num_(pnum), den_(pden)    //inizializzo num_ e den_ con i valori passati dall’utente pnum e pden
    {
    //definisco i miei concetti di Nan e Inf: in questo modo il programma non si interrompe, ma si limita ad accettare i valori dell'utente
        if (den_ == 0) { 
            //Nan
            if (num_ == 0) {
                num_ = I{0};
                den_ = I{0};
            } else {
            //Inf
                num_ = I{1};
                den_ = I{0};
            }
            return;
        } //nelle righe 26, 27, 30, 31 ho usato l'intelligenza artificiale poiché non avevo ben chiaro come definire i concetti di Inf e Nan

        if (den_ !=0) {
            I g = std::gcd(num_, den_); //massimo comun divisore
            num_ = num_/g;
            den_ = den_/g;
            return;
        }
    }

    /*Restituisco i valori di numeratore e denominatore*/
    I num() const { return num_; }
    I den() const { return den_; }

    //non ci sono vincoli di segno sull'Inf

    //SOMMA
    /* Implementazione canonica dell'incremento */
    rational& operator+=(const rational& other) {
    // NaN
    if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
        num_ = I{0};
        den_ = I{0};
        return *this;
    }
    // Inf: qui si studia il caso in cui il numeratore è diverso da 0
    if (den_ == 0 || other.den_ == 0) { 
        num_ = I{1};
        den_ = I{0};
        return *this;
    }
    //negli altri casi invece restituisco il valore della somma di due razionali
    num_ = num_ * other.den_ + other.num_ * den_;
    den_ = den_ * other.den_;

    // semplifica
    I g = std::gcd(num_, den_);
    num_ = num_/g;
    den_ = den_/g;

    return *this;
    }
    
    /* Implementazione canonica della somma */
    rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }



    //PRODOTTO
    /* Implementazione canonica di *= */
    rational& operator*=(const rational& other) {
    // NaN
    if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
        num_ = I{0};
        den_ = I{0};
        return *this;
    }
    // Inf * 0
    if ((den_ == 0 && other.num_ == 0) || (other.den_ == 1 && num_ == 1)) {
        num_ = I{0};
        den_ = I{0}; 
        return *this; //NaN
    }
    // Inf * razionale diverso da 0
    if (den_ == 0 || other.den_ == 0) {
        num_ = I{1};
        den_ = I{0};
        return *this;
    }
    //negli altri casi invece restituisco il valore del prodotto di due razionali
    num_ = num_ * other.num_;
    den_ = den_ * other.den_;

    //semplifica
    I g = std::gcd(num_, den_);
    num_ = num_/g;
    den_ = den_/g;

    return *this;
    }
    
    /* Implementazione canonica del prodotto */
    rational operator*(const rational& other) const {
    rational ret = *this;
    ret *= other;
    return ret;
    }



    //DIFFERENZA
    /* Implementazione canonica del decremento */
    rational& operator-=(const rational& other) {
    // NaN
    if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
        num_ = I{0};
        den_ = I{0};
        return *this;
    }
    // Inf - razionale
    if (den_ == 0 || other.den_ == 0) {
        num_ = I{1};
        den_ = I{0};
        return *this;
    }
    // Inf - Inf
    if (den_ == 0 && other.den_ == 0) {
        num_ = I{0};
        den_ = I{0};
        return *this; //NaN
    }
    //negli altri casi invece restituisco il valore della differenza di due razionali
    num_ = num_ * other.den_ - other.num_ * den_;
    den_ = den_ * other.den_;

    //semplifica
    I g = std::gcd(num_, den_);
    num_ = num_/g;
    den_ = den_/g;

    return *this;
    }

    /* Implementazione canonica della differenza */
    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    }



    //RAPPORTO
    /* Implementazione canonica di /= */
    rational& operator/=(const rational& other) {
    //NaN
    if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
        num_ = I{0};
        den_ = I{0};
        return *this;
    }
    //divisione per zero
    if (other.num_ == 0) {
        if (num_ == 0) {   
            num_ = I{0};
            den_ = I{0}; //NaN
        } else {           
            num_ = I{1};
            den_ = I{0}; //Inf
        }
        return *this;
    }
    //Inf / Inf
    if (den_ == 0 && other.den_ == 0) {
        num_ = I{0};
        den_ = I{0};
        return *this; //NaN
    }
    //0 / Inf 
    if (other.den_ == 0) {
        num_ = I{0};
        den_ = I{1};
        return *this; //0
    }
    //Inf / razionale
    if (den_ == 0) {
        num_ = I{1};
        den_ = I{0};
        return *this; //Inf
    }
    //negli altri casi invece restituisco il valore del rapporto di due razionali
    num_ = num_ * other.den_;
    den_ = den_ * other.num_;   

    // semplificazione
    I g = std::gcd(num_, den_);
    num_ = num_/g;
    den_ = den_/g;

    return *this;
    }

    /* Implementazione canonica del rapporto*/
    rational operator/(const rational& other) const {
    rational ret = *this;
    ret /= other;
    return ret;
    }
};


template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r)
{
    if (r.den() == 0 && r.num() == 0)
        return os << "NaN";

    if (r.den() == 0)
        return os << "Inf";

    return os << r.num() << "/" << r.den();
}