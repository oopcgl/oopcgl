#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <cmath>
#include <iostream>
#include <QtCore/qmath.h>
#include <QTime>
#include <QMouseEvent>
QImage img(400,400,QImage::Format_RGB888);
QColor color = qRgb(255,255,255);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    int x1,x2,x3,y1,y2,y3;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();
    x3 = ui->textEdit_5->toPlainText().toInt();
    y3 = ui->textEdit_6->toPlainText().toInt();
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);
}
void MainWindow::on_pushButton_2_clicked()
{
    line(200,0,200,400);
    line(0,200,400,200);
}
void MainWindow::line(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float length;
    if (abs(dx)>abs(dy)){
        length = abs(dx);
    }
    else {
        length = abs(dy);
    }
    float xinc = dx/length;
    float yinc = dy/length;
    float x = x1;
    float y = y1;
    for(int i = 0; i<= length; i++){
        x = x + xinc;
        y = y + yinc;
        img.setPixel(x,y,color.rgb());
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::on_pushButton_3_clicked()
{
    int x1 = ui->textEdit->toPlainText().toInt();
    int y1 = ui->textEdit_2->toPlainText().toInt();
    int x2 = ui->textEdit_3->toPlainText().toInt();
    int y2 = ui->textEdit_4->toPlainText().toInt();
    int x3 = ui->textEdit_5->toPlainText().toInt();
    int y3 = ui->textEdit_6->toPlainText().toInt();
    int tx = ui->textEdit_7->toPlainText().toInt();
    int ty = ui->textEdit_8->toPlainText().toInt();
    x1 += tx;
    y1 += ty;
    x2 += tx;
    y2 += ty;
    x3 += tx;
    y3 += ty;
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
void MainWindow::on_pushButton_4_clicked()
{
    int x1 = ui->textEdit->toPlainText().toInt();
    int y1 = ui->textEdit_2->toPlainText().toInt();
    int x2 = ui->textEdit_3->toPlainText().toInt();
    int y2 = ui->textEdit_4->toPlainText().toInt();
    int x3 = ui->textEdit_5->toPlainText().toInt();
    int y3 = ui->textEdit_6->toPlainText().toInt();
    float sx = ui->textEdit_9->toPlainText().toFloat();
    float sy = ui->textEdit_10->toPlainText().toFloat();
    float centroidX = (x1 + x2 + x3) / 3.0;
    float centroidY = (y1 + y2 + y3) / 3.0;
    x1 = static_cast<int>(centroidX + (x1 - centroidX) * sx);
    y1 = static_cast<int>(centroidY + (y1 - centroidY) * sy);
    x2 = static_cast<int>(centroidX + (x2 - centroidX) * sx);
    y2 = static_cast<int>(centroidY + (y2 - centroidY) * sy);
    x3 = static_cast<int>(centroidX + (x3 - centroidX) * sx);
    y3 = static_cast<int>(centroidY + (y3 - centroidY) * sy);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
void MainWindow::on_pushButton_5_clicked()
{
    int x1 = ui->textEdit->toPlainText().toInt();
    int y1 = ui->textEdit_2->toPlainText().toInt();
    int x2 = ui->textEdit_3->toPlainText().toInt();
    int y2 = ui->textEdit_4->toPlainText().toInt();
    int x3 = ui->textEdit_5->toPlainText().toInt();
    int y3 = ui->textEdit_6->toPlainText().toInt();
    float angle = ui->textEdit_12->toPlainText().toFloat();
    float radians = qDegreesToRadians(angle);
    float centroidX = (x1 + x2 + x3) / 3.0;
    float centroidY = (y1 + y2 + y3) / 3.0;
    auto rotatePoint = [centroidX, centroidY](int x, int y, float radians) {
        float cosAngle = cos(radians);
        float sinAngle = sin(radians);
        float newX = cosAngle * (x - centroidX) - sinAngle * (y - centroidY) + centroidX;
        float newY = sinAngle * (x - centroidX) + cosAngle * (y - centroidY) + centroidY;
        return std::make_pair(static_cast<int>(newX), static_cast<int>(newY));
    };
    auto rotated1 = rotatePoint(x1, y1, radians);
    auto rotated2 = rotatePoint(x2, y2, radians);
    auto rotated3 = rotatePoint(x3, y3, radians);
    line(rotated1.first, rotated1.second, rotated2.first, rotated2.second);
    line(rotated2.first, rotated2.second, rotated3.first, rotated3.second);
    line(rotated3.first, rotated3.second, rotated1.first, rotated1.second);
}

