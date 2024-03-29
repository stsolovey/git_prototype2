#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQmlContext>
#include "appcore.h"
//#include "connection.h"
#include "database/connection.h"
#include "lesson/listmodel_course.h"
int main(int argc, char *argv[])
{
    if (qEnvironmentVariableIsEmpty("QTGLESSTREAM_DISPLAY")) {
        qputenv("QT_QPA_EGLFS_PHYSICAL_WIDTH", QByteArray("213"));
        qputenv("QT_QPA_EGLFS_PHYSICAL_HEIGHT", QByteArray("120"));

        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    }

    QGuiApplication app(argc, argv);



    qmlRegisterSingletonType(QUrl("qrc:/Util.qml"), "Util", 1, 0, "Util");

    QQmlApplicationEngine engine;

    QQmlContext *context = engine.rootContext();

    Connection cn;
    //context->setContextProperty("database", &cn);

    AppCore appCore;
    context->setContextProperty("appCore", &appCore);

    /*****/


    // Объявляем и инициализируем модель данных
    ListModel *model = new ListModel();
    context->setContextProperty("myModel", model);
    /*****/


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
