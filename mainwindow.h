#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLocalSocket>
#include "pulsecontrol.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    PulseControl pc;
    QString sink = QString("1");

    ~MainWindow();
public slots:
    void updateBitrate();
    void updateBandwidth();
    void updateSignal();
    void updateComplexity();
    void updateVBR();
    void updateConstrainedVBR();
    void updateDTX();
    void updateLSB();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
