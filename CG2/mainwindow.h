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
   void mousePressEvent(QMouseEvent *events);
    ~MainWindow();

private slots:
    void line(int ,int ,int ,int);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();




private:
    Ui::MainWindow *ui;
    int count;
    bool start;
    int a[100],b[100],ver,i,xi[20],j,temp,k,m,n;
    float slope[20];
};
#endif // MAINWINDOW_H
