#include "damier.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Damier::Damier(int l, int c, int vd)
{
    Alloc(l, c);
    Init();
}

Damier::Damier(const Damier &D)
{
    Alloc(D.L, D.C);
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j] = D.T[i][j];
}


Damier::~Damier(){
    if (T != NULL) {
        Free();
        T = NULL;
    }
}

void Damier::Free(){
    for (int i=0; i<L; i++) {
        delete [] T[i];
    }
    delete [] T;
}

void Damier::Alloc(int l, int c){
    L = l;
    C = c;
    T = new int*[L];
    for(int i=0; i<L; i++)
        T[i] = new int[C];
}

void Damier::Print(){
    cout << endl;
    for(int i=0; i<L; i++) {
        cout << endl;
        for(int j=0; j<C; j++)
            cout << T[i][j] << ", ";
    }
}

void Damier::Init(){
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j]= 0;
    int i_0 = rand() % L;
    int j_0 = rand() % C;
    int valeur = (rand() % 2 + 1)*2;
    T[i_0][j_0] = valeur;
}

void Damier::Set(int l, int c, int value) {
    if ((l>=0) && (l<L) && (c>=0) & (c<C))
        T[l][c]=value;
}


void Damier::ReDim(int l, int c, int vd) {
    Free();
    Alloc(l, c);
    Init();
}

// La fonction spawn fait apparaître un 2 ou un 4 sur une case aléatoire
/*
void Damier::Spawn(){
    int i_0 = rand() % L;
    int j_0 = rand() % C;
    int valeur = (rand() % 2 + 1)*2;
    T[i][j] = valeur;
}
*/

Damier& Damier::operator= (const Damier &D){
    if ( this != &D) { // protection autoréférence
        Free();
        Alloc(D.L, D.C);
        for(int i=0; i<L; i++)
            for(int j=0; j<C; j++)
                T[i][j] = D.T[i][j];
    }
    return *this;
}
