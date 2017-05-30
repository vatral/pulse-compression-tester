#include "pulsecontrol.h"
#include <QtDebug>
#include <QtGlobal>
#include <QtNetwork>
#include <iostream>

PulseControl::PulseControl(QObject *parent) : QObject(parent)
{
    QString dir = qgetenv("XDG_RUNTIME_DIR");
    socketPath = dir + "/pulse/cli";
}

void PulseControl::init() {

    if ( socket == NULL ) {
        socket = new QLocalSocket(this);
        socket->connectToServer(socketPath);
    }
}

void PulseControl::sendCommand(QString cmd) {
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);


    qInfo() << "CMD: " << cmd;

    init();

    socket->write(data);
    socket->flush();
}
