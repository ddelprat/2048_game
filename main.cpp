#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <cstdlib>
#include <iostream>
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

int main(int argc, char *argv[])
{
    int taille=4;
    vector<vector<int>> board(taille, vector<int>(taille, 0));
    board[0][1]=2;
    board[1][0]=4;
    board[2][0]=32;

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

   /* QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url, &engine, board](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
        else if (obj == engine.rootObjects().value(0)) {
            engine.rootObjects().first()->setProperty("board", QVariant::fromValue(board));
                    }
    }, Qt::QueuedConnection);
    engine.load(url);*/

    return app.exec();
}
