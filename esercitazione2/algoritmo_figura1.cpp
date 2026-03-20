# include <iostream>

int main() {
    //array statici
    double ad[4] = {0.0, 1.1, 2.2, 3.3};                     
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    int ai[3] = {0, 1, 2};

    //definizione scalari
    int x = 1;
    float y = 1.1;

    //operazione di array su uno scalare, dovrebbe stampare qualcosa di 'ambiguo'
    (&y)[1] = 0;

    std::cout << x << "\n";

    //stampa degli indirizzi degli scalari
    std::cout << "primo scalare: ";
    std::cout << &x << "\n";
    std::cout << "secondo scalare: ";
    std::cout << &y << "\n";

    return 0;
}