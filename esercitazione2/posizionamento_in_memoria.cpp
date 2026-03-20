# include <iostream>

int main() {
    //array statici
    double ad[4] = {0.0, 1.1, 2.2, 3.3};                     
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    int ai[3] = {0, 1, 2};

    //definizione scalari
    int x = 1;
    float y = 1.1;

    //stampa degli indirizzi degli elementi costituenti l'array
    std::cout << "primo array: \n";
    for (int i=0; i<=3; i+=1) {
        std::cout << &ad[i] << "\n";
    }
    std::cout << "secondo array: \n";
    for (int i=0; i<=7; i+=1) {
        std::cout << &af[i] << "\n";
    }
    std::cout << "terzo array: \n";
    for (int i=0; i<=2; i+=1) {
        std::cout << &ai[i] << "\n";
    }

    //stampa degli indirizzi degli scalari
    std::cout << "primo scalare: ";
    std::cout << &x << "\n";
    std::cout << "secondo scalare: ";
    std::cout << &y << "\n";

    //operazione di array su uno scalare, dovrebbe stampare qualcosa di 'ambiguo'
    //(&y)[1] = 0;
    //std::cout << x << "\n";

    return 0;
}
