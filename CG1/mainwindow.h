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

private slots:
    void on_pushButton_clicked();
    void make_circle(float,float,float);
    void make_rhombus(float,float,float,float);
    void make_rectangle(float,float,float,float);
    void DDA(float,float,float,float);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
