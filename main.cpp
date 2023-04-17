#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <cstdlib>
#include <iostream>
#include<damier.h>

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
/*
Damier Test = Damier(4,4,0);

Test.Print();
Test.play_right();
Test.Print();
Test.play_left();
Test.Print();
Test.play_up();
Test.Print();
Test.play_down();
Test.Print();
cout << Test.score << endl;
*/

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

    return app.exec();
}
