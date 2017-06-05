#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

const char *bandwidths[] = {
    "narrowband",
    "mediumband",
    "wideband",
    "superwideband",
    "fullband"
};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateBitrate();
    updateSignal();
    updateBandwidth();
    updateComplexity();
    updateLSB();
    updateDTX();
    updateVBR();
    updateConstrainedVBR();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateBitrate() {
    int bitrate = ui->bitrateSlider->value();

    ui->bitrateLabel->setText( QString::number(bitrate / 1000) + " Kbps" );

    QString cmd = QString("update-sink-proplist %1 compression.bitrate=%2").arg(sink, QString::number(bitrate));

    pc.sendCommand(cmd);
}

void MainWindow::updateBandwidth() {
    const char *bw = bandwidths[ ui->bandwidthSlider->value() ];
    ui->bandwidthLabel->setText(bw);

    pc.sendCommand(QString("update-sink-proplist %1 compression.opus.max_bandwidth=\"%2\"").arg(sink).arg(bw));
}

void MainWindow::updateComplexity() {
    int complexity =  ui->complexitySlider->value();
    ui->complexityLabel->setText( QString::number(complexity));

    pc.sendCommand(QString("update-sink-proplist %1 compression.opus.complexity=\"%2\"").arg(sink).arg(complexity));
}

void MainWindow::updateLSB() {
    int lsb = ui->LSBSlider->value();
    ui->LSBLabel->setText( QString::number( lsb ) );

    pc.sendCommand(QString("update-sink-proplist %1 compression.opus.lsb_depth=\"%2\"").arg(sink).arg(lsb));
}

void MainWindow::updateSignal() {

}

void MainWindow::updateDTX() {

}

void MainWindow::updateVBR() {

}

void MainWindow::updateConstrainedVBR() {

}

