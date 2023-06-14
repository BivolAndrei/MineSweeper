#include "Minesweeper.h"
#include "BoardHandler.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

Minesweeper::Minesweeper()
{
    this->go = NEFINALIZAT;
    this->s = STEP;
    board.resetare_tabel();
    board.creare_teren();
}

void Minesweeper::afiseaza_stare()
{
    if(s==STEP)
        cout<<endl<<"Modul: STEP"<<endl;
    else
        cout<<endl<<"Modul: FLAG"<<endl;
}

void Minesweeper::afiseaza_instructiuni()
{
    cout<<endl;
    cout<<GREEN<<("=============== M I N E S W E E P E R ===============");
    cout<<endl;
    cout<<WHITE<<"INSTRUCTIUNI:";
    cout<<endl<<"-  Introduceti tasta 's' pentru a schimba intre modurile STEP si FLAG";
    cout<<endl<<"      SAU";
    cout<<endl<<"-  Daca doriti sa calcati pe casuta sau sa puneti un steag pe casuta introduceti o coordonata din tabel";
    cout<<endl<<"   exemplu: c6";
    cout<<endl<<"Pentru efectuarea comenzii introduse apasati ENTER";
    cout<<endl<<"Pentru a incepe jocul apasati ENTER";
}

int Minesweeper::convert_input(string input)
{
    if(input[0] == 's')
        return STARE;

    int d=0;
    int ok=0;
    // 97 - a   105 - i
    if(input[0]>96 && input[0]<106)
        {d=d+(input[0]-97)*10;
        ok++;}

    //48 e zero - 57 e 9
    if(input[1]>47 && input[1]<58)
        {d=d+(input[1]-49);
        ok++;}

    if(ok == 2)
        return d;


        return DATA_GRESITA;

}

void Minesweeper::gameover()
{
    for(int i=0; i<9; i++)
        for(int j=0;j<9; j++)
            if(board.b[i][j]=='+')
                return;

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(board.b[i][j]=='f')
                if(board.a[i][j]!='x')
                    return;

    go = CASTIGAT;

}

void Minesweeper::procesare_input(int d,int s)
{
    ///s reprezinta modul, adica daca sunt pe flag sau pe step
    //int x,y,i,j,ok;
    //ok=0;

    int x, y;

        y = d%10;
        x = (d/10)%10;


    if(s == FLAG && board.b[x][y] == '+')
        board.b[x][y]='f';


    if(s == STEP && board.b[x][y] == 'f')
        board.b[x][y]='+';

    else{
    if(s == STEP && board.a[x][y] == 'x')
        go = PIERDUT;


    if(s==STEP && board.a[x][y]!='x')
    {

        if(board.a[x][y]>48) //adica mai mare ca 0
        {
            board.b[x][y]=board.a[x][y];
        }
        else

        if(board.a[x][y]=='0')
        {
            board.vecinii(x,y);
        }
    }

    }
}

void Minesweeper::schimba_stare()
{
    if(s == FLAG)
        s = STEP;
    else
        s = FLAG;
}

void Minesweeper::reset_gameover_flag()
{
    go = NEFINALIZAT;
    s = STEP;
}

void Minesweeper::start()
{
std::srand(std::time(0));

    char again;
    string d;
    //Minesweeper minesweeper;
    system("clear");
    board.afisare_tabel();

    afiseaza_instructiuni();

    cin.get();


    while(1)
    {
        system("clear");
        board.afisare_tabel();
        afiseaza_stare();

        do{

    cout<<endl<<"Introduceti comanda!"<<endl;
    cin >> d;
    system("clear");




    if(convert_input(d) == DATA_GRESITA)
    {
        board.afisare_tabel();

        cout<<endl<<"Ati introdus comanda gresita!"
        <<endl<<"Introduceti comanda!"<<endl;
        cin>>d;
        system("clear");
    }

    if(convert_input(d) == STARE)
        schimba_stare();
    else
    procesare_input(convert_input(d), s);

    board.afisare_tabel();
    afiseaza_stare();
    gameover();

    }while(go == NEFINALIZAT);

    system("clear");

    if(go == PIERDUT)
    {
        board.afisare_teren();
        cout<<endl<<endl<<RED<<"Ai pierdut!  :(("<<WHITE;

    }

    if(go == CASTIGAT)
    {
        board.afisare_teren();
        cout<<endl<<endl;
        cout<<GREEN<<"Ai castigat!!!!  :O"<<WHITE;
    }

    do{
    cout<<endl<<"Doriti sa jucati din nou? <y/n>";
    cin>>again;
    }while(again!='y' && again!='n');


    if(again == 'n')
        break;

    system("clear");
    board.resetare_tabel();

    board.afisare_tabel();

    board.creare_teren();

    reset_gameover_flag();


    };
}
