#include "notes.h"
#include "ui_notes.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QString>

Notes::Notes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notes)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Notes::~Notes()
{
    delete ui;
}

void Notes::on_pushButton_3_clicked()
{
   hide();
}


void Notes::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"Информация","Напишите текст и нажмите 'Добавить', чтобы его сохранить");
}


void Notes::on_pushButton_clicked()
{
    QString t = ui->lineEdit->text();
    ui->listWidget->addItem(t);
}

