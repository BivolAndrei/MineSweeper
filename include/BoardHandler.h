#ifndef BOARDHANDLER_H
#define BOARDHANDLER_H

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

class BoardHandler
{

public:
    char a[10][10];
    char b[10][10];

    BoardHandler();

    void creare_teren(); //genereaza terenul de joc
    void afisare_teren(); //afiseaza terenul generat
    void resetare_tabel(); //reseteaza matricea tabelului
    void afisare_tabel(); //afiseaza tabelul alterat
    void vecinii(int i, int j); //metoda ce descopera casutele vecine ce au valoarea 0

};

#endif // BOARDHANDLER_H
