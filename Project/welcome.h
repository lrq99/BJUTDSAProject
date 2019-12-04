#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include "constant.h"
namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();
signals:
    void sendOpenWalkMsg();
    void sendOpenBusMsg();

private slots:
    void onPushButtonClicked();

private:
    Ui::Welcome *ui;
};

#endif // WELCOME_H
