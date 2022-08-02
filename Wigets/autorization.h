#ifndef AUTORIZATION_H
#define AUTORIZATION_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class Autorization;
}

class Autorization : public QDialog
{
    Q_OBJECT

public:
    explicit Autorization(QWidget *parent = nullptr);
    ~Autorization();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Autorization *ui;
};

#endif // AUTORIZATION_H
