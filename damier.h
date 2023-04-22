#ifndef DAMIER_H
#define DAMIER_H

#include <QObject>
#include <QVector>
/*
 *
 *
 *class Compteur : public QObject
{
    Q_OBJECT
public:
    explicit Compteur(QObject *parent = nullptr);
    Q_INVOKABLE void increment();
    Q_INVOKABLE void decrement();
    Q_PROPERTY(QString cptQML READ readCompteur NOTIFY cptChanged)


private:
    int fCompteur;
    Q_INVOKABLE QString readCompteur();

signals:
    void cptChanged();

};
 */
class Damier: public QObject {
    //Q_OBJECT
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
    Q_INVOKABLE void play_up();
    void play_down();
    void play_left();
    void play_right();
    int** T;
    std::vector<std::vector<int>> getBoard() const;
    QVector<QVector<int>> getBoardAsQvector() const;
    Q_PROPERTY(QVector<QVector<int>> board READ getBoardAsQvector NOTIFY boardChanged)
    Q_INVOKABLE QVector<QVector<int>> readBoard() const;

signals :
    void boardChanged();


private:
    int L;
    int C;



    // Méthode privée (factorisation  de code)
    void Alloc(int l, int c);
    void Free();
};


#endif // DAMIER_H
