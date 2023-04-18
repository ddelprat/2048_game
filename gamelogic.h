#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QObject>

class GameLogic : public QObject
{
    Q_OBJECT
public:
    explicit GameLogic(QObject *parent = nullptr);
    Q_INVOKABLE void playUp() {
            // Logique du jeu ici
            // appel à la méthode play_up() de la classe Damier
        }

signals:

};

#endif // GAMELOGIC_H
