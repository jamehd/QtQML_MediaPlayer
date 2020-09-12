#ifndef GESTURELISTENER_H
#define GESTURELISTENER_H

#include <QObject>
#include <QTimer>
#include <QDataStream>
#include <QLocalSocket>

#ifdef __linux__
#include "gesture_adaptor.h"
#else
#include "../HandGestureCpp/ShareGesture.h"
#endif

class GestureListener : public QObject
{
    Q_OBJECT
public:
    explicit GestureListener(QObject *parent = nullptr);

public slots:
    void gesture(int name);
    void detectProcess();
#ifndef __linux__
    void readData();
#endif
signals:
    void next();
    void prev();
    void pause();
    void play();

private:
    std::map<int, int> data_;
    QTimer circleDetect_;
#ifdef __linux__
    OpencvInterfaceAdaptor* adaptor_;
#else
    ShareGesture shareData_;
    QTimer circleReadData_;
#endif
    int currentState_;
};

#endif // GESTURELISTENER_H
