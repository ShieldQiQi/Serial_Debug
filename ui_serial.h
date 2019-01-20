/********************************************************************************
** Form generated from reading UI file 'serial.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIAL_H
#define UI_SERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Serial
{
public:
    QAction *actionQi_shield95_gmail_com;
    QAction *action2448613659;
    QAction *actionClick_me;
    QWidget *centralwidget;
    QComboBox *baudrateBox;
    QComboBox *DatabitBox;
    QComboBox *parityBox;
    QComboBox *StopbitBox;
    QComboBox *comBox;
    QLabel *BaudRatelabel;
    QLabel *DataBitlabel;
    QLabel *Paritylabel;
    QLabel *StopBitlable;
    QLabel *comlable;
    QPushButton *sendButton;
    QPlainTextEdit *replyConsole;
    QLineEdit *statusLine;
    QPushButton *ComSwitch;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QTextEdit *sendEdit;
    QPushButton *ClearButton;
    QPushButton *SaveButton;
    QPushButton *OscButton;
    QMenuBar *menubar;
    QMenu *menuHRT_D;
    QMenu *menuContract;
    QMenu *menuHelp;
    QMenu *menuTheme;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Serial)
    {
        if (Serial->objectName().isEmpty())
            Serial->setObjectName(QStringLiteral("Serial"));
        Serial->resize(858, 643);
        Serial->setStyleSheet(QStringLiteral(""));
        actionQi_shield95_gmail_com = new QAction(Serial);
        actionQi_shield95_gmail_com->setObjectName(QStringLiteral("actionQi_shield95_gmail_com"));
        action2448613659 = new QAction(Serial);
        action2448613659->setObjectName(QStringLiteral("action2448613659"));
        actionClick_me = new QAction(Serial);
        actionClick_me->setObjectName(QStringLiteral("actionClick_me"));
        centralwidget = new QWidget(Serial);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        baudrateBox = new QComboBox(centralwidget);
        baudrateBox->setObjectName(QStringLiteral("baudrateBox"));
        baudrateBox->setGeometry(QRect(748, 89, 91, 31));
        DatabitBox = new QComboBox(centralwidget);
        DatabitBox->setObjectName(QStringLiteral("DatabitBox"));
        DatabitBox->setGeometry(QRect(748, 143, 91, 31));
        parityBox = new QComboBox(centralwidget);
        parityBox->setObjectName(QStringLiteral("parityBox"));
        parityBox->setGeometry(QRect(748, 197, 91, 31));
        StopbitBox = new QComboBox(centralwidget);
        StopbitBox->setObjectName(QStringLiteral("StopbitBox"));
        StopbitBox->setGeometry(QRect(748, 251, 91, 31));
        comBox = new QComboBox(centralwidget);
        comBox->setObjectName(QStringLiteral("comBox"));
        comBox->setGeometry(QRect(748, 35, 91, 31));
        BaudRatelabel = new QLabel(centralwidget);
        BaudRatelabel->setObjectName(QStringLiteral("BaudRatelabel"));
        BaudRatelabel->setGeometry(QRect(640, 90, 91, 31));
        DataBitlabel = new QLabel(centralwidget);
        DataBitlabel->setObjectName(QStringLiteral("DataBitlabel"));
        DataBitlabel->setGeometry(QRect(640, 140, 91, 31));
        Paritylabel = new QLabel(centralwidget);
        Paritylabel->setObjectName(QStringLiteral("Paritylabel"));
        Paritylabel->setGeometry(QRect(640, 190, 91, 31));
        StopBitlable = new QLabel(centralwidget);
        StopBitlable->setObjectName(QStringLiteral("StopBitlable"));
        StopBitlable->setGeometry(QRect(640, 250, 91, 31));
        comlable = new QLabel(centralwidget);
        comlable->setObjectName(QStringLiteral("comlable"));
        comlable->setGeometry(QRect(640, 40, 91, 31));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(650, 500, 71, 31));
        replyConsole = new QPlainTextEdit(centralwidget);
        replyConsole->setObjectName(QStringLiteral("replyConsole"));
        replyConsole->setGeometry(QRect(10, 20, 611, 451));
        statusLine = new QLineEdit(centralwidget);
        statusLine->setObjectName(QStringLiteral("statusLine"));
        statusLine->setGeometry(QRect(650, 560, 181, 31));
        ComSwitch = new QPushButton(centralwidget);
        ComSwitch->setObjectName(QStringLiteral("ComSwitch"));
        ComSwitch->setGeometry(QRect(760, 500, 71, 31));
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(620, 10, 20, 471));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(-40, 470, 891, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 0, 861, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        sendEdit = new QTextEdit(centralwidget);
        sendEdit->setObjectName(QStringLiteral("sendEdit"));
        sendEdit->setGeometry(QRect(10, 490, 611, 101));
        ClearButton = new QPushButton(centralwidget);
        ClearButton->setObjectName(QStringLiteral("ClearButton"));
        ClearButton->setGeometry(QRect(650, 310, 71, 31));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        SaveButton->setGeometry(QRect(650, 360, 71, 31));
        OscButton = new QPushButton(centralwidget);
        OscButton->setObjectName(QStringLiteral("OscButton"));
        OscButton->setGeometry(QRect(650, 410, 111, 31));
        Serial->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Serial);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 858, 25));
        menuHRT_D = new QMenu(menubar);
        menuHRT_D->setObjectName(QStringLiteral("menuHRT_D"));
        menuContract = new QMenu(menubar);
        menuContract->setObjectName(QStringLiteral("menuContract"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuTheme = new QMenu(menubar);
        menuTheme->setObjectName(QStringLiteral("menuTheme"));
        Serial->setMenuBar(menubar);
        statusbar = new QStatusBar(Serial);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Serial->setStatusBar(statusbar);

        menubar->addAction(menuHRT_D->menuAction());
        menubar->addAction(menuContract->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuTheme->menuAction());
        menuContract->addSeparator();
        menuContract->addAction(actionQi_shield95_gmail_com);
        menuContract->addAction(action2448613659);
        menuHelp->addAction(actionClick_me);

        retranslateUi(Serial);

        QMetaObject::connectSlotsByName(Serial);
    } // setupUi

    void retranslateUi(QMainWindow *Serial)
    {
        Serial->setWindowTitle(QApplication::translate("Serial", "MainWindow", Q_NULLPTR));
        actionQi_shield95_gmail_com->setText(QApplication::translate("Serial", "qi.shield95@gmail.com", Q_NULLPTR));
        action2448613659->setText(QApplication::translate("Serial", "2448613659", Q_NULLPTR));
        actionClick_me->setText(QApplication::translate("Serial", "Click me", Q_NULLPTR));
        BaudRatelabel->setText(QApplication::translate("Serial", " Baud Rate", Q_NULLPTR));
        DataBitlabel->setText(QApplication::translate("Serial", "  DataBit", Q_NULLPTR));
        Paritylabel->setText(QApplication::translate("Serial", "  Parity", Q_NULLPTR));
        StopBitlable->setText(QApplication::translate("Serial", " Stop Bits", Q_NULLPTR));
        comlable->setText(QApplication::translate("Serial", "    Com", Q_NULLPTR));
        sendButton->setText(QApplication::translate("Serial", "Send", Q_NULLPTR));
        ComSwitch->setText(QApplication::translate("Serial", "ON", Q_NULLPTR));
        ClearButton->setText(QApplication::translate("Serial", "Clear", Q_NULLPTR));
        SaveButton->setText(QApplication::translate("Serial", "Save", Q_NULLPTR));
        OscButton->setText(QApplication::translate("Serial", "Oscilloscope", Q_NULLPTR));
        menuHRT_D->setTitle(QApplication::translate("Serial", "HRT_D", Q_NULLPTR));
        menuContract->setTitle(QApplication::translate("Serial", "Contract", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("Serial", "Help", Q_NULLPTR));
        menuTheme->setTitle(QApplication::translate("Serial", "Theme", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Serial: public Ui_Serial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAL_H
