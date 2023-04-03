#ifndef DAMIER_H
#define DAMIER_H

#include <QObject>

class Damier: public QObject
{
public:
    Damier(int l, int c, int vd);
    Damier(const Damier &D);
    ~Damier();

    Damier& operator=  (const Damier &D); // opérateur d'affectation
    int score;
    bool loose = false;
    void Print();
    void Init();
    void Set(int x, int y, int value);
    void ReDim(int l, int c, int vd = 0);
    void Spawn();
    void play_up();
    void play_down();
    void play_left();
    void play_right();


private:
    int L;
    int C;
    int** T;

    // Méthode privée (factorisation  de code)
    void Alloc(int l, int c);
    void Free();
};


#endif // DAMIER_H
