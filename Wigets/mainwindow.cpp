#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "notes.h"
#include "calculator.h"

#include <QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPixmap pix(":/rec/img/widget.png");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_2_triggered()
{
    exit(0);
}


void MainWindow::on_action_triggered()
{
    showMinimized();
}


void MainWindow::on_action_hovered()
{
    ui->statusbar->showMessage("Свернуть приложение");
}


void MainWindow::on_action_2_hovered()
{
    ui->statusbar->showMessage("Закрыть приложение");
}


void MainWindow::on_pushButton_clicked()
{
    Notes window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    Calculator  calc;
    calc.setModal(true);
    calc.exec();
}

