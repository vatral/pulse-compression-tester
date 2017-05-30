#ifndef PULSECONTROL_H
#define PULSECONTROL_H

#include <QLocalSocket>


class PulseControl : public QObject
{
    Q_OBJECT
public:
    explicit PulseControl(QObject *parent = 0);
    QString socketPath;

    void sendCommand(QString cmd);
private:
    QLocalSocket *socket;
    void init();
signals:

public slots:
};

#endif // PULSECONTROL_H
