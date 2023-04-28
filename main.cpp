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
#include <QVector>
#include <QQmlContext>
#include <damierq.h>

using namespace std;




int main(int argc, char *argv[])
{
    int taille = 4;
    DamierQ boardGame = DamierQ(taille,taille,0);
    boardGame.Print();
    boardGame.restart();
    boardGame.play_down();
    /*cout <<"score";
    cout << boardGame.score;
    cout <<"best";
    cout << boardGame.best;
    boardGame.Print();
    boardGame.play_up();
    boardGame.Print();
    boardGame.play_right();
    boardGame.Print();*/



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

    engine.rootContext()->setContextProperty("vueObjetBoardGame", &boardGame);
   // QObject *rootObject = engine.rootObjects().first();



    /*QVariant qVariantBoardGame = QVariant::fromValue(&boardGame);
    rootObject->setProperty("boardGame", qVariantBoardGame);*/

    /*QVariant qVariantBoard = QVariant::fromValue(qboard);
    rootObject->setProperty("board", qVariantBoard);*/


    return app.exec();
}
