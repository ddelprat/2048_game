#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <cstdlib>
#include <iostream>
#include <damier.h>

#include <QLocale>
#include <QTranslator>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QLocale>
#include <QTranslator>
#include <QVariant>
#include <vector>
#include <iostream>
using namespace std;
/*
void playUp(std::vector<std::vector<int>>& board)
{
    board.play_up();
}*/


int main(int argc, char *argv[])
{
    int taille = 4;
    Damier BoardGame = Damier(taille, taille, 0);
    std::vector<std::vector<int>> board = BoardGame.getBoard();

    #if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    #endif

    QGuiApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "2048_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    QObject *rootObject = engine.rootObjects().first();
    QVariant qVariantBoard = QVariant::fromValue(board);
    rootObject->setProperty("board", qVariantBoard);

    /*
    // Ajouter le contexte pour la fonction playUp
    QQmlContext* context = engine.rootContext();
    context->setContextProperty("playUp", &playUp);
*/
    return app.exec();
}
