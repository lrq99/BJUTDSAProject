/********************************************************************************
** Form generated from reading UI file 'walkroute.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WALKROUTE_H
#define UI_WALKROUTE_H

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

class Ui_WalkRoute
{
public:
    QLabel *startLabel;
    QLabel *endLabel;
    QLineEdit *startEdit;
    QLineEdit *endEdit;
    QPushButton *queryButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *ClearButton;
    QLabel *LabelStartPos;
    QLabel *LabelEndPos;
    QLabel *label_8;
    QPushButton *NextPathButton;
    QPushButton *PrevPathButton;
    QLabel *totallen;
    QLabel *LabelRoute;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;

    void setupUi(QWidget *WalkRoute)
    {
        if (WalkRoute->objectName().isEmpty())
            WalkRoute->setObjectName(QStringLiteral("WalkRoute"));
        WalkRoute->resize(1500, 750);
        startLabel = new QLabel(WalkRoute);
        startLabel->setObjectName(QStringLiteral("startLabel"));
        startLabel->setGeometry(QRect(1150, 100, 41, 16));
        endLabel = new QLabel(WalkRoute);
        endLabel->setObjectName(QStringLiteral("endLabel"));
        endLabel->setGeometry(QRect(1160, 140, 31, 20));
        startEdit = new QLineEdit(WalkRoute);
        startEdit->setObjectName(QStringLiteral("startEdit"));
        startEdit->setGeometry(QRect(1200, 100, 231, 21));
        endEdit = new QLineEdit(WalkRoute);
        endEdit->setObjectName(QStringLiteral("endEdit"));
        endEdit->setGeometry(QRect(1200, 140, 231, 21));
        queryButton = new QPushButton(WalkRoute);
        queryButton->setObjectName(QStringLiteral("queryButton"));
        queryButton->setGeometry(QRect(1210, 180, 93, 28));
        label = new QLabel(WalkRoute);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1191, 450, 191, 20));
        label_2 = new QLabel(WalkRoute);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1190, 480, 201, 20));
        label_3 = new QLabel(WalkRoute);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1190, 510, 201, 20));
        label_4 = new QLabel(WalkRoute);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1190, 540, 201, 20));
        label_5 = new QLabel(WalkRoute);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1190, 570, 251, 20));
        label_6 = new QLabel(WalkRoute);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1190, 600, 251, 20));
        label_7 = new QLabel(WalkRoute);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1160, 420, 171, 16));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(9);
        label_7->setFont(font);
        label_7->setCursor(QCursor(Qt::ArrowCursor));
        label_7->setTextFormat(Qt::AutoText);
        ClearButton = new QPushButton(WalkRoute);
        ClearButton->setObjectName(QStringLiteral("ClearButton"));
        ClearButton->setGeometry(QRect(1330, 180, 93, 28));
        LabelStartPos = new QLabel(WalkRoute);
        LabelStartPos->setObjectName(QStringLiteral("LabelStartPos"));
        LabelStartPos->setGeometry(QRect(1200, 290, 281, 16));
        LabelEndPos = new QLabel(WalkRoute);
        LabelEndPos->setObjectName(QStringLiteral("LabelEndPos"));
        LabelEndPos->setGeometry(QRect(1200, 320, 281, 16));
        label_8 = new QLabel(WalkRoute);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1190, 630, 251, 20));
        NextPathButton = new QPushButton(WalkRoute);
        NextPathButton->setObjectName(QStringLiteral("NextPathButton"));
        NextPathButton->setGeometry(QRect(1210, 220, 93, 28));
        PrevPathButton = new QPushButton(WalkRoute);
        PrevPathButton->setObjectName(QStringLiteral("PrevPathButton"));
        PrevPathButton->setGeometry(QRect(1330, 220, 93, 28));
        totallen = new QLabel(WalkRoute);
        totallen->setObjectName(QStringLiteral("totallen"));
        totallen->setGeometry(QRect(1200, 350, 201, 16));
        LabelRoute = new QLabel(WalkRoute);
        LabelRoute->setObjectName(QStringLiteral("LabelRoute"));
        LabelRoute->setGeometry(QRect(1200, 380, 201, 16));
        label_9 = new QLabel(WalkRoute);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1190, 660, 251, 20));
        label_10 = new QLabel(WalkRoute);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(1190, 690, 251, 20));
        label_11 = new QLabel(WalkRoute);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(1190, 720, 291, 20));

        retranslateUi(WalkRoute);

        QMetaObject::connectSlotsByName(WalkRoute);
    } // setupUi

    void retranslateUi(QWidget *WalkRoute)
    {
        WalkRoute->setWindowTitle(QApplication::translate("WalkRoute", "Widget", Q_NULLPTR));
        startLabel->setText(QApplication::translate("WalkRoute", "Start", Q_NULLPTR));
        endLabel->setText(QApplication::translate("WalkRoute", "End", Q_NULLPTR));
        startEdit->setText(QApplication::translate("WalkRoute", "Gate No.4", Q_NULLPTR));
        endEdit->setText(QApplication::translate("WalkRoute", "Gate No.2", Q_NULLPTR));
        queryButton->setText(QApplication::translate("WalkRoute", "Query", Q_NULLPTR));
        label->setText(QApplication::translate("WalkRoute", "\345\233\255\350\211\272\345\260\217\351\225\207:Gardening Town", Q_NULLPTR));
        label_2->setText(QApplication::translate("WalkRoute", "\345\233\275\351\231\205\351\246\206:International Hall", Q_NULLPTR));
        label_3->setText(QApplication::translate("WalkRoute", "\344\270\255\345\233\275\351\246\206:Chinese Hall", Q_NULLPTR));
        label_4->setText(QApplication::translate("WalkRoute", "\345\246\253\346\261\255\345\211\247\345\234\272:Guirui Theatre", Q_NULLPTR));
        label_5->setText(QApplication::translate("WalkRoute", "\347\224\237\346\264\273\344\275\223\351\252\214\351\246\206:Life Experience Hall", Q_NULLPTR));
        label_6->setText(QApplication::translate("WalkRoute", "\346\244\215\347\211\251\351\246\206:Botanical Hall", Q_NULLPTR));
        label_7->setText(QApplication::translate("WalkRoute", "[\346\263\250]\345\220\204\346\231\257\347\202\271\345\220\215\347\247\260\345\246\202\344\270\213\357\274\232", Q_NULLPTR));
        ClearButton->setText(QApplication::translate("WalkRoute", "Clear", Q_NULLPTR));
        LabelStartPos->setText(QApplication::translate("WalkRoute", "Start :", Q_NULLPTR));
        LabelEndPos->setText(QApplication::translate("WalkRoute", "End :", Q_NULLPTR));
        label_8->setText(QApplication::translate("WalkRoute", "\346\260\270\345\256\201\351\230\201:Yongning Pavilion", Q_NULLPTR));
        NextPathButton->setText(QApplication::translate("WalkRoute", "NextPath", Q_NULLPTR));
        PrevPathButton->setText(QApplication::translate("WalkRoute", "PrevPath", Q_NULLPTR));
        totallen->setText(QApplication::translate("WalkRoute", "Total Length :", Q_NULLPTR));
        LabelRoute->setText(QApplication::translate("WalkRoute", "Route :", Q_NULLPTR));
        label_9->setText(QApplication::translate("WalkRoute", "\345\272\267\345\273\266\350\267\257:Kangyan Road", Q_NULLPTR));
        label_10->setText(QApplication::translate("WalkRoute", "\345\246\253\346\261\255\346\271\226:Guirui Lake", Q_NULLPTR));
        label_11->setText(QApplication::translate("WalkRoute", "1\357\274\2102,4,5,6\357\274\211\345\217\267\351\227\250:Gate No.1/2/4/5/6", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WalkRoute: public Ui_WalkRoute {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WALKROUTE_H
