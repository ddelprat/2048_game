#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <cstdlib>
#include <iostream>

#include <QLocale>
#include <QTranslator>
using namespace std;

int main(int argc, char *argv[])
{
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
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}


/*
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <cstdlib>
#include <iostream>

#include <QLocale>
#include <QTranslator>
#include <QVariantList>
#include <QVariantMap>
using namespace std;

QVariantList getGridData() {
    QVariantList dataList;
    // switch case pour affecter les couleurs en fonction des valeurs
    for(int i=0; i<16; i++){
        QVariantMap data;
        int value = pow(2, i);
        data["display"] = value > 0 ? QString::number(value) : "";
        switch(value) {
            case 0:
                data["color"] = "#ffffff";
                break;
            case 2:
                data["color"] = "#ffff99";
                break;
            case 4:
                data["color"] = "#ff6666";
                break;
            case 8:
                data["color"] = "#3399ff";
                break;
            case 16:
                data["color"] = "#ff9933";
                break;
            case 32:
                data["color"] = "#00cc66";
                break;
            case 64:
                data["color"] = "#996633";
                break;
            case 128:
                data["color"] = "#ff66cc";
                break;
            case 256:
                data["color"] = "#6600cc";
                break;
            case 512:
                data["color"] = "#ffcc00";
                break;
            case 1024:
                data["color"] = "#404040";
                break;
            case 2048:
                data["color"] = "#ff0066";
                break;
            default:
                data["color"] = "#ffffff";
        }
        dataList.append(data);
    }
    return dataList;
}

int main(int argc, char *argv[])
{
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
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("gridModel", QVariant::fromValue(getGridData()));

    engine.load(url);

    return app.exec();
}

*/
