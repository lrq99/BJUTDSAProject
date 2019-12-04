#include "welcome.h"
#include "ui_welcome.h"
#include <QMessageBox>
Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    this->setWindowTitle("Tour Guide Application");

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onPushButtonClicked()));
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::onPushButtonClicked()
{
    if(ui->radioButton->isChecked()){
        emit sendOpenWalkMsg();
    }
    else if(ui->radioButton_2->isChecked()){
        emit sendOpenBusMsg();
    }else{
        QMessageBox::information(this, "Error!", "You didn't select any option.");
    }
}
