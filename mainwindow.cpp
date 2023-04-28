#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QtMath>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setWindowFlags(Qt::CustomizeWindowHint);
    setWindowFlag(Qt::WindowMinimizeButtonHint);
    setWindowFlag(Qt::WindowCloseButtonHint);
    qApp->setWindowIcon(QIcon(":rec/Calc2.png"));

    connect(ui->Button1, SIGNAL(clicked()), this, SLOT(btnclick()));
    connect(ui->Button2, SIGNAL(clicked()), this, SLOT(btnclick()));
    connect(ui->Button3, SIGNAL(clicked()), this, SLOT(btnclick()));
    connect(ui->Button4, SIGNAL(clicked()), this, SLOT(btnclick()));
    connect(ui->Button5, SIGNAL(clicked()), this, SLOT(btnclick()));
    connect(ui->Button6, SIGNAL(clicked()), this, SLOT(btnclick()));
    connect(ui->Button7, SIGNAL(clicked()), this, SLOT(btnclick()));
    connect(ui->Button8, SIGNAL(clicked()), this, SLOT(btnclick()));
    connect(ui->Button9, SIGNAL(clicked()), this, SLOT(btnclick()));
    connect(ui->Button0, SIGNAL(clicked()), this, SLOT(btnclick()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::btnclick()
{
    QPushButton *Btn = (QPushButton *)sender();

    ui->lineEdit->setText(ui->lineEdit->text()+ Btn->text() );

}

void MainWindow::on_ButAC_clicked()
{
    ui->lineEdit->setText(0);
    ui->label->setText(0);
}

void MainWindow::on_Kvadrat_clicked()
{
    double a = ui->lineEdit->text().toDouble();
    ui->lineEdit->setText(QString::number(a*a));
}

void MainWindow::on_PlusMinus_clicked()
{
    QString str = ui->lineEdit->text();
    if (str[0] != '-' && str != "")
        ui->lineEdit->setText("-"+ui->lineEdit->text());
    else
        ui->lineEdit->setText(str.remove("-"));
}

void MainWindow::on_Koren_clicked()
{
    double a = ui->lineEdit->text().toDouble();
    ui->lineEdit->setText(QString::number( sqrt(a)));
}

void MainWindow::on_pushButton_24_clicked()
{
    int a = ui->lineEdit->text().toUInt();
    ui->lineEdit->setText(QString::number(qPow(10,a)));
}

void MainWindow::on_ButtonTchka_clicked()
{
    if (!(ui->lineEdit->text().contains(".")) && !(ui->lineEdit->text()==""))
    {
        ui->lineEdit->setText(ui->lineEdit->text()+".");
    }

}

void MainWindow::on_ButMSave_clicked()
{
    double a = ui->lineEdit->text().toDouble();
    memory = a;
    QString stri = QString::number(memory);
    ui->label_2->setText(stri);
    //ui->label_2->setNum(memory);
}

void MainWindow::on_ButMminus_clicked()
{
    ui->lineEdit->setText(QString::number(memory - ui->lineEdit->text().toDouble()));
}

void MainWindow::on_ButMplus_clicked()
{
    ui->lineEdit->setText(QString::number(memory + ui->lineEdit->text().toDouble()));

}

void MainWindow::on_ButMC_clicked()
{
    memory = 0;
    ui->label_2->setText("Ничего");
}

void MainWindow::on_ButMR_clicked()
{
    ui->lineEdit->setText(QString::number(memory));
}

void MainWindow::on_Stepen_clicked()
{
    gl1 = ui->lineEdit->text().toDouble();
    cin = 1;
    ui->lineEdit->setText(0);
    ui->label->setText("''");
}

void MainWindow::on_plus_clicked()
{
    gl1 = ui->lineEdit->text().toDouble();
    cin = 2;
    ui->lineEdit->setText(0);
    ui->label->setText("+");

}

void MainWindow::on_minus_clicked()
{
    gl1 = ui->lineEdit->text().toDouble();
    cin = 3;
    ui->lineEdit->setText(0);
    ui->label->setText("-");

}

void MainWindow::on_umnozh_clicked()
{
    gl1 = ui->lineEdit->text().toDouble();
    cin = 4;
    ui->lineEdit->setText(0);
    ui->label->setText("*");

}

void MainWindow::on_Delete_clicked()
{
    gl1 = ui->lineEdit->text().toDouble();
    cin = 5;
    ui->lineEdit->setText(0);
    ui->label->setText("/");

}

void MainWindow::on_Ravno_clicked()
{
    double res;
    double gl2 = ui->lineEdit->text().toDouble();
    switch (cin)
    {
    case 1:{
        res = qPow(gl1,gl2);
        break;}
    case 2:{
        res = gl1+gl2;
        break;}
    case 3:{
        res = gl1-gl2;
        break;}
    case 4:{
        res = gl1*gl2;
        break;}
    case 5:{
        res = gl1/gl2;
        break;}
    case 6:{
        res = (gl1/100)*gl2;
        break;}
    }
    QString stri = QString::number(res);
    if (stri.length()>7)
        ui->lineEdit->setText(QString::number(res,'f',3));
    else
        ui->lineEdit->setText(QString::number(res));




}

void MainWindow::on_SBack_clicked()
{
    if (ui->lineEdit->text()=="")
        ui->label->setText(0);
    QString str = ui->lineEdit->text();
    str.chop(1);
    ui->lineEdit->setText(str);

}

void MainWindow::on_Procent_clicked()
{
    gl1 = ui->lineEdit->text().toDouble();
    cin = 6;
    ui->lineEdit->setText(0);
    ui->label->setText("%");

}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,"Руководство","1)Процент(%): Первым нужно ввести число от которого брать процент , после нажать кнопку % и ввести сам процент после нажать равно. \n2)Возвести 10 в степень Х(10**Х): Ввести нужную степень и нажать кнопку 10**Х \n !!! Окошко с синей рамкой показывает то , что находится в памяти калькулятора");

}


