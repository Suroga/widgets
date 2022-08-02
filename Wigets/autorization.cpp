#include "autorization.h"
#include "ui_autorization.h"
#include "mainwindow.h"
#include <QString>
#include <QMessageBox>

Autorization::Autorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Autorization)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Autorization::~Autorization()
{
    delete ui;
}

void Autorization::on_pushButton_clicked()
{
    QString login = ui->login->text();
    QString password = ui->password->text();
    if (login == "Sergey" && password == "Lazuka") {
        this->close();
    } else {
        QMessageBox::warning(this, "Информация", "Вы не авторизовались!");
    };
}


void Autorization::on_pushButton_2_clicked()
{
    exit(0);
}

