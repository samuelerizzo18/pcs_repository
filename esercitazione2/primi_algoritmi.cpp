# include <iostream>
# include <cmath>

int main() {
    //definisco array double
    static const int N = 10;
    double arr[N] = {0.0, 1.6, 8.9, 7.5, 4.2, 8.1, 5.4, 0.5, -1.2, -3.8};

    //ricerco il minimo
    double minimo = arr[0];
    for (int i = 1; i <= N-1; i+=1) {
        if (arr[i] < minimo)
            minimo = arr[i]; 
    }
    std::cout << "Minimo: " << minimo << "\n";

    //ricerco il massimo
    double massimo = arr[0];
    for (int i = 1; i <= N-1; i+=1) {
        if (arr[i] > massimo)
            massimo = arr[i]; 
    }
    std::cout << "Massimo: " << massimo << "\n";

    //calcolo la media
    double somma = 0;
    for (int i = 0; i <= N-1; i+=1) {
        somma = somma + arr[i];
    }
    double media;
    media = somma/N;
    std::cout << "Media: " << media << "\n";

    //calcolo la deviazione standard
    double risultato_i = 0;
    double sum = 0;
    for (int i = 0; i <= N-1; i+=1) {
        risultato_i = (arr[i] - media)*(arr[i] - media);
        sum = sum + risultato_i; 
    }   
    double deviazione_standard = std::sqrt(sum / N);
    std::cout << "Deviazione standard: " << deviazione_standard << "\n";

}