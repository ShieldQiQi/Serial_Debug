#include "serial.h"
#include <QTimer>
#include <QMessageBox>
#include <QFile>

Serial::Serial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Serial)
{
    ui->setupUi(this);

    fillPortParameters();
    fillPortInfo();
    loadProfileFromDisk(); // Get saved profile st startup

    ui->statusLine->setText("Disconnected");
    ui->sendButton->setStyleSheet ("border-radius: 10px;border: 2px groove gray;border-style: outset;");
    ui->comlable->setStyleSheet("border-radius: 10px;border: 2px groove gray;");
    ui->StopBitlable->setStyleSheet("border-radius: 10px;border: 2px groove gray;");
    ui->BaudRatelabel->setStyleSheet("border-radius: 10px;border: 2px groove gray;");
    ui->Paritylabel->setStyleSheet("border-radius: 10px;border: 2px groove gray;");
    ui->DataBitlabel->setStyleSheet("border-radius: 10px;border: 2px groove gray;");

    serialPort = new QSerialPort(this);

    connect(serialPort, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(readSerialData()));
    connect(ui->sendButton, SIGNAL(clicked(bool)), this, SLOT(on_SendButton_clicked()));
    connect(ui->ComSwitch, SIGNAL(clicked(bool)), this, SLOT(SwitchCom()));
    connect(ui->ClearButton,SIGNAL(clicked(bool)), this, SLOT(Clear()));
    connect(ui->SaveButton,SIGNAL(clicked(bool)), this, SLOT(on_SaveButton_Clicked()));
    connect(ui->actionClick_me,SIGNAL(triggered(bool)), this, SLOT(Show_My_AliPay()));

    connect(ui->baudrateBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(Apply()));
    connect(ui->parityBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(Apply()));
    connect(ui->StopbitBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(Apply()));
    connect(ui->DatabitBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(Apply()));

    //定时刷新串口、每隔200ms
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Refresh()));
    timer->start(200);

}

// Return a valid communication port set of values
Serial::SerialProfile Serial::profile() const
{
  return currentProfile;
}

// Collect the manufacturer information for each connected serial device.
void Serial::fillPortInfo()
{
  ui->comBox->clear();
  //遍历每个串口、并在combox添加串口号
  foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
    QStringList list;
    list << info.portName();
    ui->comBox->addItem(list.first(), list);
  }
}

// Fill the list boxes with all possible serial port settings
void Serial::fillPortParameters()
{
  ui->baudrateBox->addItem(QStringLiteral("1200"), QSerialPort::Baud1200);
  ui->baudrateBox->addItem(QStringLiteral("2400"), QSerialPort::Baud2400);
  ui->baudrateBox->addItem(QStringLiteral("4800"), QSerialPort::Baud4800);
  ui->baudrateBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
  ui->baudrateBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
  ui->baudrateBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
  ui->baudrateBox->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
  ui->baudrateBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);

  ui->DatabitBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
  ui->DatabitBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
  ui->DatabitBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
  ui->DatabitBox->addItem(QStringLiteral("8"), QSerialPort::Data8);

  ui->parityBox->addItem(QStringLiteral("None"), QSerialPort::NoParity);
  ui->parityBox->addItem(QStringLiteral("Even"), QSerialPort::EvenParity);
  ui->parityBox->addItem(QStringLiteral("Odd"), QSerialPort::OddParity);
  ui->parityBox->addItem(QStringLiteral("Mark"), QSerialPort::MarkParity);
  ui->parityBox->addItem(QStringLiteral("Space"), QSerialPort::SpaceParity);

  ui->StopbitBox->addItem(QStringLiteral("1"), QSerialPort::OneStop);
#ifdef Q_OS_WIN
  ui->StopbitBox->addItem(QStringLiteral("1.5"), QSerialPort::OneAndHalfStop);
#endif
  ui->StopbitBox->addItem(QStringLiteral("2"), QSerialPort::TwoStop);
}

// Read all list boxes and set the communication profile based on the contents.
void Serial::updateProfile()
{ // Stringxxxxx entries are for use with text objects to display the profile.
  currentProfile.name = ui->comBox->currentText();

  currentProfile.baudRate = static_cast<QSerialPort::BaudRate>(ui->baudrateBox->itemData(ui->baudrateBox->currentIndex()).toInt());
  currentProfile.stringBaudRate = QString::number(currentProfile.baudRate);

  currentProfile.dataBits = static_cast<QSerialPort::DataBits>(ui->DatabitBox->itemData(ui->DatabitBox->currentIndex()).toInt());
  currentProfile.stringDataBits = ui->DatabitBox->currentText();

  currentProfile.parity = static_cast<QSerialPort::Parity>(ui->parityBox->itemData(ui->parityBox->currentIndex()).toInt());
  currentProfile.stringParity = ui->parityBox->currentText();

  currentProfile.stopBits = static_cast<QSerialPort::StopBits>(ui->StopbitBox->itemData(ui->StopbitBox->currentIndex()).toInt());
  currentProfile.stringStopBits = ui->StopbitBox->currentText();

}

// Read current list box values and save them to disk
void Serial::saveProfileToDisk()
{
  QSettings setting("SerialProfile.ini", QSettings::IniFormat);
  setting.beginGroup("SerialProfile");
  setting.setValue("name", ui->comBox->currentText());
  setting.setValue("baudRate", ui->baudrateBox->currentIndex());
  setting.setValue("dataBits", ui->DatabitBox->currentIndex());
  setting.setValue("parity", ui->parityBox->currentIndex());
  setting.setValue("stopBits", ui->StopbitBox->currentIndex());
  setting.endGroup();
}

// Read saved profile and restore all list box selections
void Serial::loadProfileFromDisk()
{
  QSettings setting("SerialProfile.ini", QSettings::IniFormat);
  setting.beginGroup("SerialProfile");

  // Look for a matching communication port name
  int index = ui->comBox->findText(setting.value("name", QString("none")).toString(),Qt::MatchExactly);
  if (index != -1) { // If a matching port name is found set the list box to display the saved communication port
    ui->comBox->setCurrentIndex(index);
  }
  // Fill the rest of the list boxes based on the current index (fillPortsParameters fills the same every time)
  ui->baudrateBox->setCurrentIndex(setting.value("baudRate", int(3)).toInt());
  ui->DatabitBox->setCurrentIndex(setting.value("dataBits", int(3)).toInt());
  ui->parityBox->setCurrentIndex(setting.value("parity", int(0)).toInt());
  ui->StopbitBox->setCurrentIndex(setting.value("stopBits", int(0)).toInt());
  setting.endGroup();
  updateProfile();
}

// Accept current selection set
void Serial::Apply()
{
    updateProfile();
    serialPort->setPortName(currentProfile.name);
    serialPort->setBaudRate(currentProfile.baudRate);
    serialPort->setDataBits(currentProfile.dataBits);
    serialPort->setParity(currentProfile.parity);
    serialPort->setStopBits(currentProfile.stopBits);
    saveProfileToDisk();
    //hide();
}

void Serial::Refresh() // Refresh port list (new ports might be added i.e. USB to serial)
{
  fillPortInfo();
  if(serialPort->isOpen())
  {
      ui->ComSwitch->setText(QString("ON"));
      ui->ComSwitch->setStyleSheet("background-color: rgb(0, 255, 0);");
  }else{
      ui->statusLine->setText("Disconnected");
      ui->ComSwitch->setText(QString("OFF"));
      ui->ComSwitch->setStyleSheet("background-color: rgb(255, 0, 0);");
  }
  readSerialData();
}

void Serial::connectSerialPort()
{
  if (serialPort->isOpen()) {
  } else {
    SerialProfile profile = this->profile();  // Get current serial profile

    serialPort->setPortName(profile.name);
    serialPort->setBaudRate(profile.baudRate);
    serialPort->setDataBits(profile.dataBits);
    serialPort->setParity(profile.parity);
    serialPort->setStopBits(profile.stopBits);
    if (serialPort->open(QIODevice::ReadWrite)) {
      ui->statusLine->setText(QString("serial is ready: %1")
                              .arg(profile.name));
    } else {
      ui->statusLine->setText(tr("Serial error: ") + serialPort->errorString());
    }
  }
}

void Serial::disconnectSerialPort()
{
  if (serialPort->isOpen()) {
    serialPort->close();
  }
}

void Serial::writeSerialData(QByteArray data)
{
  if (serialPort->isOpen()) {
    data.append("\r"); // add newline
    qDebug() << data;
    serialPort->write(data);
    serialPort->waitForBytesWritten(1000); // Provide serial device blocking.
  } else {
    ui->statusLine->setText("No serial device open");
  }
}

void Serial::readSerialData()
{
    QTextCursor c = ui->replyConsole->textCursor();
    c.movePosition(QTextCursor::End);
    ui->replyConsole->setTextCursor(c);

    static QByteArray Serial_buff;
    Serial_buff+=serialPort->readAll();
    //格式转换、防止中文乱码
    QString myStrTemp=QString::fromLocal8Bit(Serial_buff);
    ui->replyConsole->insertPlainText(myStrTemp);
    Serial_buff.clear();

//    ui->replyConsole->ensureCursorVisible();

}

void Serial::handleError(QSerialPort::SerialPortError error)
{
  if (error == QSerialPort::ResourceError) {
    ui->statusLine->setText("Critical Error" + serialPort->errorString());
    disconnectSerialPort();
  }
}

//****************** Menu & Toolbar ******************

void Serial::on_actionClear_triggered()
{
  ui->replyConsole->clear();
}

//****************** Buttons ******************
void Serial::on_SendButton_clicked()
{
  writeSerialData(ui->sendEdit->toPlainText().toLocal8Bit());
}

void Serial::Clear()
{
  ui->replyConsole->clear();
}

void Serial::on_SaveButton_Clicked()
{
    QFile file("E:/Desktop/Data.txt");

    //判断文件是否存在
    if(file.exists())
    {
        QMessageBox::warning(this,"Create file","file aleady exits!");
    }else
    {
        //存在打开，不存在创建
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        //写入QByteArray格式字符串
        file.write(ui->replyConsole->toPlainText().toUtf8());
        //提示成功
        QMessageBox::warning(this,"Create file","Create successfully");
    }
    //关闭文件
    file.close();
}

void Serial::SwitchCom()
{
  if(serialPort->isOpen())
  {
      disconnectSerialPort();
  }else{
      connectSerialPort();
  }
}

void Serial::Show_My_AliPay()
{
    QMainWindow* popwindow= new QMainWindow;

    QPixmap pixmap = QPixmap("E:/HRT-19D/ECU/7 software/ComTool/image/myAliPay.jpg").scaled(QSize(300,300));
    QPalette  palette (this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    popwindow->setPalette( palette );

    popwindow->setWindowTitle("AliPay");
    popwindow->setFixedSize(300,300);
    popwindow->show();
}

void Serial::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QLinearGradient linearGradient(629,33,851,800);
    linearGradient.setColorAt(0,QColor(180,180,180));
    linearGradient.setColorAt(0.4,QColor(240,240,230));
    linearGradient.setColorAt(1,QColor(220,223,227));
    painter.setBrush(linearGradient);
    painter.drawRect(QRect(629,34,222,470));
    painter.drawRect(QRect(629,512,222,110));

    painter.setBrush(QColor(199,237,204));//设置画刷形式
    painter.drawRect(QRect(5,34,620,470));
    painter.drawRect(QRect(5,512,620,110));
}

Serial::~Serial()
{
    delete ui;
}

