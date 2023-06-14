#include "BoardHandler.h"
#include <iostream>
#include <cstdlib>
using namespace std;
void BoardHandler::creare_teren()
{
int x,y,ok=0;

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            a[i][j]='0';

    do{

    x=rand()%9;
    y=rand()%9;

    if(a[x][y]!='x')
        {a[x][y]='x';
        ok++;}

    }while(ok<9); ///pana cand am plasat 10 bombe

    ok=0;

    /// parcurgem mijlocul matricei
    for(int i=1;i<8;i++)
        for(int j=1;j<8;j++)
            {
                ok=0;

            if(a[i][j]!='x')
            {

                if(a[i-1][j-1]=='x')
                    ok++;

                if(a[i-1][j]=='x')
                ok++;

                if(a[i-1][j+1]=='x')
                ok++;

                if(a[i][j-1]=='x')
                ok++;

                if(a[i][j+1]=='x')
                ok++;

                if(a[i+1][j+1]=='x')
                ok++;

                if(a[i+1][j]=='x')
                ok++;

                if(a[i+1][j-1]=='x')
                ok++;

                a[i][j]=ok+48;
            }

            }

    /// parcurgem colturile matricei

    ok=0;

    ///coltul stanga sus
    if(a[0][0]!='x')
    {
        if(a[0][1]=='x')
            ok++;

        if(a[1][1]=='x')
            ok++;

        if(a[1][0]=='x')
            ok++;

        a[0][0]=ok+48;
    }

    ///coltul dreapta sus
    ok=0;

        if(a[0][8]!='x')
    {
        if(a[0][7]=='x')
            ok++;

        if(a[1][7]=='x')
            ok++;

        if(a[1][8]=='x')
            ok++;

        a[0][8]=ok+48;
    }

    ///coltul stanga jos
    ok=0;
        if(a[8][0]!='x')
    {
        if(a[7][0]=='x')
            ok++;

        if(a[7][1]=='x')
            ok++;

        if(a[8][1]=='x')
            ok++;

        a[8][0]=ok+48;
    }

    ///coltul dreapta jos
    ok=0;
        if(a[8][8]!='x')
    {
        if(a[8][7]=='x')
            ok++;

        if(a[7][7]=='x')
            ok++;

        if(a[7][8]=='x')
            ok++;

        a[8][8]=ok+48;
    }


    ///parcurgem rama matricei fara colturi


    for (int i=1;i<8;i++)
    {

        ///rama sus
        ok=0;
        if(a[0][i]!='x')
        {
            if(a[0][i-1]=='x')
                ok++;

            if(a[1][i-1]=='x')
                ok++;

            if(a[1][i]=='x')
                ok++;

            if(a[1][i+1]=='x')
                ok++;

            if(a[0][i+1]=='x')
                ok++;

                a[0][i]=ok+48;
        }

                ///rama jos
        ok=0;
        if(a[8][i]!='x')
        {
            if(a[8][i-1]=='x')
                ok++;

            if(a[7][i-1]=='x')
                ok++;

            if(a[7][i]=='x')
                ok++;

            if(a[7][i+1]=='x')
                ok++;

            if(a[8][i+1]=='x')
                ok++;

            a[8][i]=ok+48;
        }

        ///rama stanga

        ok=0;
        if(a[i][0]!='x')
        {
            if(a[i-1][0]=='x')
                ok++;

            if(a[i-1][1]=='x')
                ok++;

            if(a[i][1]=='x')
                ok++;

            if(a[i+1][1]=='x')
                ok++;

            if(a[i+1][0]=='x')
                ok++;

            a[i][0]=ok+48;
        }

        ///rama dreapta
                ok=0;
        if(a[i][8]!='x')
        {
            if(a[i-1][8]=='x')
                ok++;

            if(a[i-1][7]=='x')
                ok++;

            if(a[i][7]=='x')
                ok++;

            if(a[i+1][7]=='x')
                ok++;

            if(a[i+1][8]=='x')
                ok++;

            a[i][8]=ok+48;
        }

    }
}

void BoardHandler::afisare_tabel()
{

    char d=97;
    //SetConsoleTextAttribute(h,14); yellow
    cout<<" | ";
    for(int i=0;i<9;i++)
        cout<<i+1<<" | ";

    cout<<endl;

    for(int i=0;i<9;i++)
        cout<<" - -";

    cout<<endl;
    for(int i=0;i<9;i++)
        {

        cout<<d<<"| ";
        d++;
        for(int j=0;j<9;j++)
            {

            if(b[i][j]=='1')
            {
            //SetConsoleTextAttribute(h,3);
            cout<<CYAN<<b[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(b[i][j]=='2')
            {
            //SetConsoleTextAttribute(h,2);
            cout<<GREEN<<b[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(b[i][j]=='3')
            {
            //SetConsoleTextAttribute(h,12);
            cout<<RED<<b[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(b[i][j]=='4')
            {
            //SetConsoleTextAttribute(h,13);
            cout<<MAGENTA<<b[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(b[i][j]=='5')
            {
            //SetConsoleTextAttribute(h,4);
            cout<<BLUE<<b[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(b[i][j]=='6')
            {
            //SetConsoleTextAttribute(h,10);
            cout<<YELLOW<<b[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(b[i][j]=='7')
            {
            //SetConsoleTextAttribute(h,14);
            cout<<GREEN<<b[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(b[i][j]=='8')
            {
            //SetConsoleTextAttribute(h,6);
            cout<<RED<<b[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }


            if(b[i][j]=='f')
            {
            //SetConsoleTextAttribute(h,6);
            cout<<YELLOW<<b[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(b[i][j]=='x' || b[i][j]=='0' || b[i][j]=='+')
            {

                cout<<b[i][j];cout<<" | ";}


            }

        cout<<endl;
            for(int i=0;i<9;i++)
        cout<<" - -";

        cout<<endl;
        }
}

void BoardHandler::afisare_teren()
{

        char d=97;
    cout<<" | ";
    for(int i=0;i<9;i++)
        cout<<i+1<<" | ";

    cout<<endl;

    for(int i=0;i<9;i++)
        cout<<" - -";

    cout<<endl;
    for(int i=0;i<9;i++)
        {

        cout<<d<<"| ";
        d++;
        for(int j=0;j<9;j++)
            {

            if(a[i][j]=='1')
            {
            //SetConsoleTextAttribute(h,3);
            cout<<CYAN<<a[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(a[i][j]=='2')
            {
            //SetConsoleTextAttribute(h,2);
            cout<<GREEN<<a[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(a[i][j]=='3')
            {
            //SetConsoleTextAttribute(h,12);
            cout<<RED<<a[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(a[i][j]=='4')
            {
            //SetConsoleTextAttribute(h,13);
            cout<<MAGENTA<<a[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(a[i][j]=='5')
            {
            //SetConsoleTextAttribute(h,4);
            cout<<BLUE<<a[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(a[i][j]=='6')
            {
            //SetConsoleTextAttribute(h,10);
            cout<<YELLOW<<a[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(a[i][j]=='7')
            {
            //SetConsoleTextAttribute(h,14);
            cout<<GREEN<<a[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(a[i][j]=='8')
            {
            //SetConsoleTextAttribute(h,6);
            cout<<RED<<a[i][j];
            //SetConsoleTextAttribute(h,7);
            cout<<WHITE<<" | ";
            }

            if(a[i][j]=='x' || a[i][j]=='0')
            {cout<<a[i][j];cout<<" | ";}


            }

        cout<<endl;
            for(int i=0;i<9;i++)
        cout<<" - -";

        cout<<endl;
        }

}



void BoardHandler :: resetare_tabel()
{
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            b[i][j]='+';
}

void BoardHandler :: vecinii (int i, int j)
{

    ///in cazul in care casuta este descoperita
    ///nu se mai ia in considerare
    if(b[i][j]!='+')
        return;



    b[i][j] = a[i][j];

    if(i-1>-1 && j-1>-1)
        {
            if(a[i-1][j-1]=='0')
            {   vecinii(i-1,j-1);
                b[i-1][j-1]=a[i-1][j-1];

            }

            else if(a[i-1][j-1]<57)
            {
                b[i-1][j-1]=a[i-1][j-1];
            }

        }

        //2
        if(i-1>-1)
        {
             if(a[i-1][j]=='0')
                {   vecinii(i-1,j);
                    b[i-1][j]=a[i-1][j];

                }
                else if(a[i-1][j]<57)
                {
                    b[i-1][j]=a[i-1][j];
                }

        }

        //3
        if(i-1>-1 && j+1<9)
        {
                if(a[i-1][j+1]=='0')
                {   vecinii(i-1,j+1);
                    b[i-1][j+1]=a[i-1][j+1];

                }
                else if(a[i-1][j+1]<57)
                {
                    b[i-1][j+1]=a[i-1][j+1];
                }

        }

        //4
        if(j+1<9)
        {
            if(a[i][j+1]=='0')
                {   vecinii(i,j+1);
                    b[i][j+1] = a[i][j+1];

                }
                else if(a[i][j+1]<57)
                {
                    b[i][j+1] = a[i][j+1];
                }

        }

        //5
        if(i+1<9 && j+1<9)
        {
            if(a[i+1][j+1]=='0')
                {   vecinii(i+1,j+1);
                    b[i+1][j+1] = a[i+1][j+1];

                }
                else if(a[i+1][j+1]<57)
                {
                    b[i+1][j+1] = a[i+1][j+1];
                }

        }

        //6
        if(i+1<9)
        {
            if(a[i+1][j]=='0')
                {   vecinii(i+1,j);
                   b[i+1][j] = a[i+1][j];

                }
                else if (a[i+1][j]<57)
                {
                   b[i+1][j] = a[i+1][j];
                }

        }

        //7
        if(i+1<9 && j-1>-1)
        {
            if(a[i+1][j-1]=='0')
                {   vecinii(i+1,j-1);
                    b[i+1][j-1] = a[i+1][j-1];

                }
                else if(a[i+1][j-1]<57)
                {
                    b[i+1][j-1] = a[i+1][j-1];
                }


        }

        //8
        if(j-1>-1)
        {
            if(a[i][j-1]=='0')
                {   vecinii(i,j-1);
                   b[i][j-1] = a[i][j-1];

                }else if(a[i][j-1]<57)
                {
                   b[i][j-1] = a[i][j-1];
                }


        }


}

BoardHandler::BoardHandler()
{
    creare_teren();
    resetare_tabel();
}

