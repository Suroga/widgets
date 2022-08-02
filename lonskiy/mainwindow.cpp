#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QString>
//#include <QStringConverter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/res/image/hod.jpg");
    int w = ui->image_hod->width();
    int h = ui->image_hod->height();

    ui->statusbar->showMessage("Введите высоты и колличество пунктов. Дробную часть отделять точкой");
    ui->image_hod->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->lineEdit->setText("185.314");
    ui->lineEdit_2->setText("201.062");
    ui->spinBox->setValue(7);
    ui->tableView->hide();
    ui->tableView_2->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int row = ui->spinBox->value();
    model = new QStandardItemModel(row, 3 , this);
    model->setHeaderData(0, Qt::Horizontal , "Превышение\nпрямое,\nм");
    model->setHeaderData(1, Qt::Horizontal , "Превышениt\nобратное,\nм");
    model->setHeaderData(2, Qt::Horizontal , "Длина\nсекции,\nкм");
    QModelIndex index;
    for (int r = 0; r<row; r++)
        {
            index = model->index(r,0);
            model->setData(index, -10 + rand()%20 );
        }
    for (int r = 0; r<row; r++)
        {
            index = model->index(r,1);
            model->setData(index, -10 + rand()%20 );
        }
    for (int r = 0; r<row; r++)
        {
            index = model->index(r,2);
            model->setData(index, -10 + rand()%20 );
        }

    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->pushButton_3->show();
    ui->pushButton_2->show();
    ui->statusbar->showMessage("Введите исходные данные в таблицу. Дробную часть отделять точкой");

}


void MainWindow::on_pushButton_2_clicked()
{
    int row = ui->spinBox->value();
    //float a[row], b[0], c[0], d[0], e[0], f[0], g[0];
    //a[row];
    //for (int r = 0; r < row ; r++) {
    //    float pull1,pull2;
    //    pull1 = model->item(r,0)->text().toFloat();
    //    pull2 = (model->item(r,1)->text()).toFloat();
    //    if (pull1 < 0) {
    //       pull1 = pull1 * -1;
    //        a[r] = (pull1+pull2)/2*-1;
    //    }
    //    else{
    //        pull2 = pull2 * -1;
    //        a[r] = (pull1+pull2)/2;
    //    }
    //}
    model = new QStandardItemModel(row, 7 , this);
    model->setHeaderData(0, Qt::Horizontal , "Среднее\nпревышение,\nм");
    model->setHeaderData(1, Qt::Horizontal , "d, м");
    model->setHeaderData(2, Qt::Horizontal , "Дополнительное\nпревышение,\nм");
    model->setHeaderData(3, Qt::Horizontal , "d2,\nкв.м");
    model->setHeaderData(4, Qt::Horizontal , "d2/L,\nкв.м/км");
    model->setHeaderData(5, Qt::Horizontal , "Поправка V,\nм");
    model->setHeaderData(6, Qt::Horizontal , "Исправленное\nпревышение, м");
    QModelIndex index;
    for (int r = 0; r<row; r++)
        {
            index = model->index(r,0);
            model->setData(index, -10 + rand()%20 );
        }
    for (int r = 0; r<row; r++)
        {
            index = model->index(r,1);
            model->setData(index, -20 + rand()%40 );
        }
    for (int r = 0; r<row; r++)
        {
            index = model->index(r,2);
            model->setData(index, 63 + rand()%300 );
        }
    for (int r = 0; r<row; r++)
        {
            index = model->index(r,3);
            model->setData(index, rand()%10 );
        }
    for (int r = 0; r<row; r++)
        {
            index = model->index(r,4);
            model->setData(index, rand()%10 );
        }
    for (int r = 0; r<row; r++)
        {
            index = model->index(r,5);
            model->setData(index, rand()%10 );
        }
    for (int r = 0; r<row; r++)
        {
            index = model->index(r,6);
            model->setData(index,-20 + rand()%40 );
        }

    ui->tableView_2->setModel(model);
    ui->tableView_2->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableView_2->hide();
    ui->tableView->hide();
    ui->pushButton_3->hide();
    ui->pushButton_2->hide();
}

