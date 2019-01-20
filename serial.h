#pragma once

#include <QMainWindow>
#include <QSettings>
#include <QtAlgorithms>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QPlainTextEdit>
#include "ui_serial.h"
#include <QPainter>

namespace Ui {
class Serial;
}

class Serial : public QMainWindow
{
    Q_OBJECT

public:
    struct SerialProfile { // Structure to hold a complete set of communication port parameters
      QString name;
      qint32 baudRate;
      QString stringBaudRate;
      QSerialPort::DataBits dataBits;
      QString stringDataBits;
      QSerialPort::Parity parity;
      QString stringParity;
      QSerialPort::StopBits stopBits;
      QString stringStopBits;
    };

    explicit Serial(QWidget *parent = 0);
    ~Serial();
    void paintEvent(QPaintEvent *event);
    SerialProfile profile() const;

private slots:
    void Apply();
    void Refresh();

    void connectSerialPort();
    void disconnectSerialPort();
    void writeSerialData(QByteArray data);
    void readSerialData();
    void handleError(QSerialPort::SerialPortError error);

    //Menu and tool bar actions

    void on_SendButton_clicked();
    void on_actionClear_triggered();
    void SwitchCom();
    void Clear();
    void on_SaveButton_Clicked();
    void Show_My_AliPay();

private:
    void loadProfileFromDisk();
    void saveProfileToDisk();
    void fillPortParameters();
    void fillPortInfo();
    void updateProfile();

private:
    Ui::Serial *ui;
    SerialProfile currentProfile;
    QSerialPort *serialPort;
};

