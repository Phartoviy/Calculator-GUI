#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double memory;
    double gl1;
    double gl2;
    int cin;
    int s= 0;
private slots:
    void on_ButAC_clicked();
    void btnclick();

    void on_Kvadrat_clicked();

    void on_PlusMinus_clicked();

    void on_Koren_clicked();

    void on_pushButton_24_clicked();

    void on_ButtonTchka_clicked();

    void on_ButMSave_clicked();

    void on_ButMminus_clicked();

    void on_ButMplus_clicked();

    void on_ButMC_clicked();

    void on_ButMR_clicked();

    void on_Stepen_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_umnozh_clicked();

    void on_Delete_clicked();

    void on_Ravno_clicked();

    void on_SBack_clicked();

    void on_Procent_clicked();

    void on_actionAbout_triggered();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
