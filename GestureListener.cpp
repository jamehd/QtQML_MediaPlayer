#include "GestureListener.h"

#include <QtNetwork>

GestureListener::GestureListener(QObject *parent) : QObject(parent)
{
    currentState_ = 0;
#ifdef __linux__
    adaptor_ = new OpencvInterfaceAdaptor(this);
    QDBusConnection connection_ = QDBusConnection::sessionBus();
    connection_.registerObject("/petproject", this);
    connection_.registerService("petproject.opencvInterface");
#else
    QObject::connect(&circleReadData_ , &QTimer::timeout, this, &GestureListener::readData);
    circleReadData_.setInterval(24);
    circleReadData_.start();
#endif
    QObject::connect(&circleDetect_ , &QTimer::timeout, this, &GestureListener::detectProcess);
    circleDetect_.setInterval(1000);
    circleDetect_.start();
}

void GestureListener::gesture(int name)
{
    if (data_.count(name) != 0) {
        data_[name]++;
    } else {
        data_[name] = 1;
    }
}

void GestureListener::detectProcess()
{
    auto res = std::max_element(data_.begin(),
                                data_.end(),
                                [](std::map<int, int>::value_type largest, std::map<int, int>::value_type first){
               return largest.second < first.second; });
    data_.clear();

    if (res->second != currentState_) {
        switch (res->first) {
            case 3:
                emit next(); break;
            case 2:
                emit prev(); break;
            case 4:
                emit pause(); break;
            case 5:
                emit play(); break;
            default:
                break;
        }
    }

    qDebug() << "RESSSSSS" << res->first;
}

void GestureListener::readData()
{
    auto data = shareData_.read();
    gesture(data);
}
