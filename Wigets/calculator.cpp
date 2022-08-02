#include "calculator.h"
#include "ui_calculator.h"
#include <QMessageBox>

double num_first;

Calculator::Calculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_ant,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_div->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);

}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::on_pushButton_21_clicked()
{
    hide();
}


void Calculator::on_pushButton_18_clicked()
{
    QMessageBox::information(this, "Информация", "Простой калькулятор");
}

void Calculator::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if(ui->result_label->text().contains('.') && button->text() == "0"){
        new_label = ui->result_label->text() + button->text();
    } else
    {
    all_numbers = (ui->result_label->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 15);
    }
    ui->result_label->setText(new_label);

}


void Calculator::on_pushButton_dot_clicked()
{
    if(!(ui->result_label->text().contains('.')))
        ui->result_label->setText( ui->result_label->text() + ".");
}

void Calculator::operations()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    if(button->text() == "+/-")
    {
        all_numbers = (ui->result_label->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->result_label->setText(new_label);
    } else if (button->text() == "%")
    {
        all_numbers = (ui->result_label->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->result_label->setText(new_label);
    }

}


void Calculator::on_pushButton_ac_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_div->setChecked(false);

    ui->result_label->setText("0");
}


void Calculator::on_pushButton_equally_clicked()
{
    double label_number, num_second;
    QString new_label;

    num_second = ui->result_label->text().toDouble();

    if(ui->pushButton_plus->isChecked())
    {
        label_number = num_first + num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->result_label->setText(new_label);
        ui->pushButton_plus->setChecked(false);


    } else if(ui->pushButton_minus->isChecked())
    {
        label_number =num_first - num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->result_label->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    } else if(ui->pushButton_multiply->isChecked())
    {
        label_number =num_first * num_second ;
        new_label = QString::number(label_number, 'g', 15);

        ui->result_label->setText(new_label);
        ui->pushButton_multiply->setChecked(false);
    } else if(ui->pushButton_div->isChecked())
    {
        if (num_second == 0)
            ui->result_label->setText("0");
        else {
        label_number = num_first / num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->result_label->setText(new_label);
        }
        ui->pushButton_div->setChecked(false);
    }

}

void Calculator::math_operations()
{
    QPushButton *button = (QPushButton *)sender();

    num_first = ui->result_label->text().toDouble();
    ui->result_label->setText("");

    button->setChecked(true);


}
