#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void dda(float x1, float y1, float x2, float y2);
    void dda2(float x1, float y1, float x2, float y2);
    int regioncode(double,double);
    bool clipping(double &, double &, double &, double &);
    void window();
    void window1();
    double x1,y1,x2,y2;

    int code1,code2;
    int xmin=100,xmax=200,ymin=100,ymax=200;
    const int Top=8,Bot=4,Right=2,Left=1;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

//    void on_pushButton_3_clicked();

//    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
