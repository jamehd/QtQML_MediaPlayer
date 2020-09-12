#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "player.h"
#include <QQmlContext>
#include "playlistmodel.h"
#include "translation.h"
#include "GestureListener.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qRegisterMetaType<QMediaPlaylist*>("QMediaPlaylist*");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Translation translator(&app);
    Player player;
    GestureListener listener;
    engine.rootContext()->setContextProperty("gestureListener",&listener);
    engine.rootContext()->setContextProperty("myModel",player.m_playlistModel);
    engine.rootContext()->setContextProperty("player",player.m_player);
    engine.rootContext()->setContextProperty("utility",&player);
    engine.rootContext()->setContextProperty("translator",&translator);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
