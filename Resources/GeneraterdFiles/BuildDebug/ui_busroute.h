/********************************************************************************
** Form generated from reading UI file 'busroute.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUSROUTE_H
#define UI_BUSROUTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BusRoute
{
public:
    QLabel *startLabel;
    QLabel *endlabel;
    QLineEdit *startEdit;
    QLineEdit *endEdit;
    QPushButton *queryButton;
    QPushButton *clearButton;
    QLabel *endloc;
    QLabel *startloc;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *transformloc;
    QLabel *totallen;

    void setupUi(QWidget *BusRoute)
    {
        if (BusRoute->objectName().isEmpty())
            BusRoute->setObjectName(QStringLiteral("BusRoute"));
        BusRoute->setEnabled(true);
        BusRoute->resize(1576, 946);
        startLabel = new QLabel(BusRoute);
        startLabel->setObjectName(QStringLiteral("startLabel"));
        startLabel->setEnabled(true);
        startLabel->setGeometry(QRect(1310, 170, 72, 15));
        endlabel = new QLabel(BusRoute);
        endlabel->setObjectName(QStringLiteral("endlabel"));
        endlabel->setEnabled(true);
        endlabel->setGeometry(QRect(1310, 220, 72, 15));
        startEdit = new QLineEdit(BusRoute);
        startEdit->setObjectName(QStringLiteral("startEdit"));
        startEdit->setEnabled(true);
        startEdit->setGeometry(QRect(1362, 170, 201, 21));
        endEdit = new QLineEdit(BusRoute);
        endEdit->setObjectName(QStringLiteral("endEdit"));
        endEdit->setEnabled(true);
        endEdit->setGeometry(QRect(1362, 220, 201, 21));
        queryButton = new QPushButton(BusRoute);
        queryButton->setObjectName(QStringLiteral("queryButton"));
        queryButton->setEnabled(true);
        queryButton->setGeometry(QRect(1330, 270, 93, 28));
        clearButton = new QPushButton(BusRoute);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setEnabled(true);
        clearButton->setGeometry(QRect(1450, 270, 93, 28));
        endloc = new QLabel(BusRoute);
        endloc->setObjectName(QStringLiteral("endloc"));
        endloc->setEnabled(true);
        endloc->setGeometry(QRect(1230, 400, 301, 16));
        startloc = new QLabel(BusRoute);
        startloc->setObjectName(QStringLiteral("startloc"));
        startloc->setEnabled(true);
        startloc->setGeometry(QRect(1230, 370, 291, 16));
        label_5 = new QLabel(BusRoute);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1230, 670, 251, 20));
        label_4 = new QLabel(BusRoute);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1230, 640, 281, 20));
        label = new QLabel(BusRoute);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1231, 550, 301, 20));
        label_2 = new QLabel(BusRoute);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1230, 580, 291, 20));
        label_8 = new QLabel(BusRoute);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1230, 730, 321, 20));
        label_7 = new QLabel(BusRoute);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1230, 520, 171, 16));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(9);
        label_7->setFont(font);
        label_7->setCursor(QCursor(Qt::ArrowCursor));
        label_7->setTextFormat(Qt::AutoText);
        label_3 = new QLabel(BusRoute);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1230, 610, 231, 20));
        label_6 = new QLabel(BusRoute);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1230, 700, 261, 20));
        label_9 = new QLabel(BusRoute);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1230, 760, 321, 20));
        label_10 = new QLabel(BusRoute);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(1230, 790, 441, 21));
        label_11 = new QLabel(BusRoute);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(1230, 840, 321, 20));
        label_12 = new QLabel(BusRoute);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(1230, 870, 321, 20));
        label_13 = new QLabel(BusRoute);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(1230, 810, 441, 21));
        transformloc = new QLabel(BusRoute);
        transformloc->setObjectName(QStringLiteral("transformloc"));
        transformloc->setEnabled(true);
        transformloc->setGeometry(QRect(1230, 430, 311, 16));
        totallen = new QLabel(BusRoute);
        totallen->setObjectName(QStringLiteral("totallen"));
        totallen->setEnabled(true);
        totallen->setGeometry(QRect(1230, 460, 311, 16));

        retranslateUi(BusRoute);

        QMetaObject::connectSlotsByName(BusRoute);
    } // setupUi

    void retranslateUi(QWidget *BusRoute)
    {
        BusRoute->setWindowTitle(QApplication::translate("BusRoute", "Form", Q_NULLPTR));
        startLabel->setText(QApplication::translate("BusRoute", "start", Q_NULLPTR));
        endlabel->setText(QApplication::translate("BusRoute", "end", Q_NULLPTR));
        startEdit->setText(QApplication::translate("BusRoute", "Gate No.2 Station", Q_NULLPTR));
        endEdit->setText(QApplication::translate("BusRoute", "Guirui Theater Station", Q_NULLPTR));
        queryButton->setText(QApplication::translate("BusRoute", "Query", Q_NULLPTR));
        clearButton->setText(QApplication::translate("BusRoute", "Clear", Q_NULLPTR));
        endloc->setText(QApplication::translate("BusRoute", "End:", Q_NULLPTR));
        startloc->setText(QApplication::translate("BusRoute", "Start:", Q_NULLPTR));
        label_5->setText(QApplication::translate("BusRoute", "\344\270\255\345\233\275\351\246\206\347\253\231:China Pavilion Station", Q_NULLPTR));
        label_4->setText(QApplication::translate("BusRoute", "\344\270\226\345\233\255\347\276\216\345\256\266\347\253\231:Shiyuan May joy Station", Q_NULLPTR));
        label->setText(QApplication::translate("BusRoute", "\345\233\255\350\211\272\345\260\217\351\225\207\347\253\231:Horticulture Town Station", Q_NULLPTR));
        label_2->setText(QApplication::translate("BusRoute", "\347\231\276\350\224\254\345\233\255\347\253\231:Vegetables Garden Station", Q_NULLPTR));
        label_8->setText(QApplication::translate("BusRoute", "\345\233\275\351\231\205\351\246\206\347\253\231:International Pavilion Station", Q_NULLPTR));
        label_7->setText(QApplication::translate("BusRoute", "[\346\263\250]\345\220\204\346\231\257\347\202\271\345\220\215\347\247\260\345\246\202\344\270\213\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("BusRoute", "6\345\217\267\351\227\250\347\253\231:Gate No.6 Station", Q_NULLPTR));
        label_6->setText(QApplication::translate("BusRoute", "\345\246\253\346\261\255\345\211\247\345\234\272\347\253\231:Guirui Theater Station", Q_NULLPTR));
        label_9->setText(QApplication::translate("BusRoute", "2\345\217\267\351\227\250\347\253\231:Gate No.2 Station", Q_NULLPTR));
        label_10->setText(QApplication::translate("BusRoute", "\347\224\237\346\264\273\344\275\223\351\252\214\351\246\206\347\253\231: Horticultural Experience", Q_NULLPTR));
        label_11->setText(QApplication::translate("BusRoute", "5\345\217\267\351\227\250\347\253\231:Gate No.5 Station", Q_NULLPTR));
        label_12->setText(QApplication::translate("BusRoute", "1\345\217\267\351\227\250\347\253\231:Gate No.1 Station", Q_NULLPTR));
        label_13->setText(QApplication::translate("BusRoute", "             Pavilion Station", Q_NULLPTR));
        transformloc->setText(QApplication::translate("BusRoute", "Transform:", Q_NULLPTR));
        totallen->setText(QApplication::translate("BusRoute", "Total Length: ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BusRoute: public Ui_BusRoute {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSROUTE_H
