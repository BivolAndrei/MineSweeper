#ifndef Minesweeper_H
#define Minesweeper_H
#include "BoardHandler.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
#define GREEN "\033[32m"
#define RED "\033[31m"
#define WHITE "\033[37m"

enum stari_joc {NEFINALIZAT, PIERDUT, CASTIGAT};
enum tipuri_data_intrare {COORDONATA = -3, STARE, DATA_GRESITA};
enum tip_stare {STEP, FLAG};

class Minesweeper
{
private:
    int go; //'go' de la gameover si poate avea valorile
    //NEFINALIZAT/ PIERDUT/ CASTIGAT

    int s; //corespunde starii STEP/FLAG

public:

    BoardHandler board; //obiect ce reprezinta tabla jocului

    Minesweeper(); //constructorul

    void afiseaza_stare(); //afiseaza starea curenta (STEP/FLAG)
    void afiseaza_instructiuni(); //afiseaza instructiunile jocului

    int convert_input(string input); //returneaza data introdusa
    void gameover(); //verifica daca jocul a fost castigat

    void procesare_input(int d, int s); //Modifica tabelul in functie de data introdusa
    void schimba_stare(); //interschimba intre modurile STEP/FLAG
    void reset_gameover_flag(); //Reseteaza starea jocului ca fiind NEFINALIZAT
    //dupa finalizarea lui.

    void start(); //ruleaza jocul

};

#endif // Minesweeper_H
