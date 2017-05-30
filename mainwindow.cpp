#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

char *bandwidths[] = {
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
    ui->bitrateLabel->setText( QString::number(ui->bitrateSlider->value() / 1000) + " Kbps" );
}

void MainWindow::updateBandwidth() {
    ui->bandwidthLabel->setText(bandwidths[ ui->bandwidthSlider->value() ]);
}

void MainWindow::updateComplexity() {
    ui->complexityLabel->setText( QString::number( ui->complexitySlider->value() ));
}

void MainWindow::updateLSB() {
    ui->LSBLabel->setText( QString::number( ui->LSBSlider->value()) );
}

void MainWindow::updateSignal() {

}

void MainWindow::updateDTX() {

}

void MainWindow::updateVBR() {

}

void MainWindow::updateConstrainedVBR() {

}

