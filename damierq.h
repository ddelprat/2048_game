#ifndef DAMIERQ_H
#define DAMIERQ_H

#include <QObject>

class DamierQ : public QObject
{
    Q_OBJECT
public:
    //explicit DamierQ(int rows, int cols, int defaultValue, QObject *parent = nullptr);
    explicit DamierQ(int l, int c, int vd, QObject *parent = nullptr);
    //DamierQ(int l, int c, int vd, QObject *parent = nullptr);
    DamierQ(const DamierQ &D, QObject *parent = nullptr);
    ~DamierQ();

    DamierQ& operator=  (const DamierQ &D); // opérateur d'affectation
    int score;
    bool loose = false;
    void Print();
    void Init();
    void Set(int x, int y, int value);
    void ReDim(int l, int c, int vd = 0);
    void Spawn();
    Q_INVOKABLE void play_up();
    Q_INVOKABLE void play_down();
    Q_INVOKABLE void play_left();
    Q_INVOKABLE void play_right();
    int** T;
    std::vector<std::vector<int>> getBoard() const;
    Q_INVOKABLE QVector<QVector<int>> getBoardAsQvector() const;
    Q_PROPERTY(QVector<QVector<int>> board READ getBoardAsQvector NOTIFY boardChanged)
    Q_INVOKABLE QVector<QVector<int>> readBoard() const;

signals:
    void boardChanged();

private:
    int L;
    int C;

    // Méthode privée (factorisation  de code)
    void Alloc(int l, int c);
    void Free();
};


#endif // DAMIERQ_H