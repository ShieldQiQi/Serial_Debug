#pragma execution_character_set("utf-8")
#include "serial.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Serial w;
    w.setWindowTitle(QString::fromUtf8("无人车串口调试助手V0.0"));
    w.setFixedSize(855,642);
    w.setWindowIcon(QIcon("./image/hrt.ico"));

    w.show();

    return a.exec();
}
