#include "mainwindow.h"
#include "ui_mainwindow.h"
QImage img(500, 500 , QImage::Format_RGB888);

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
    int x1,y1,l,b,xc,yc,r;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    l=ui->textEdit_3->toPlainText().toInt();
    b=ui->textEdit_4->toPlainText().toInt();
    xc=ui->textEdit_5->toPlainText().toInt();
    yc=ui->textEdit_6->toPlainText().toInt();
    r=ui->textEdit_7->toPlainText().toInt();

    make_rectangle(x1,y1,l,b);
    make_rhombus(x1,y1,l,b);
    make_circle(xc,yc,r);

}


void MainWindow::DDA(float x1, float y1, float x2, float y2)
{
    int x,y;
    float dx, dy, length ,xinc , yinc;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy))
    {
        length=abs(dx);
    }
   else
    {
        length=abs(dy);
    }
    xinc=dx/length;
    yinc=dy/length;

    x=x1;
    y=y1;
    int i=0;
    while(i<length)
    {
       img.setPixel(x,y,qRgb(255,255,0));
        x=x+xinc;
        y=y+yinc;
        i++;
    }
}


void MainWindow::make_circle(float xc ,float yc,float r)
{
    int x=0 , y=r;
    int d=3-(2*r);

    while(x<=y){
        //putpixels
        img.setPixel(x+xc,y+yc,qRgb(255,255,0));
        img.setPixel(y+xc,x+yc,qRgb(255,255,0));
        img.setPixel(x+xc,-y+yc,qRgb(255,255,0));
        img.setPixel(y+xc,-x+yc,qRgb(255,255,0));
        img.setPixel(-y+xc,-x+yc,qRgb(255,255,0));
        img.setPixel(-x+xc,-y+yc,qRgb(255,255,0));
        img.setPixel(-x+xc,y+yc,qRgb(255,255,0));
        img.setPixel(-y+xc,x+yc,qRgb(255,255,0));


        if(d<0){
            d = d+4*x+6;
        }
        else{
            d = d+4*(x-y)+10;
            y = y-1;
        }
        x=x+1;
    }
     ui->label_8->setPixmap(QPixmap::fromImage(img));

}


void MainWindow::make_rectangle(float x1,float y1,float l,float b)
{
    DDA(x1 ,y1,x1,y1+b);
    DDA(x1 ,y1,(x1+l),y1);
    DDA((x1+l) ,y1,(x1+l),(y1+b));
    DDA(x1 ,(y1+b),(x1+l),(y1+b));

    ui->label_8->setPixmap((QPixmap::fromImage(img)));
}

void MainWindow::make_rhombus(float x1,float y1,float l,float b)
{
    DDA(x1 ,(y1+(b/2)),(x1+(l/2)),y1);
    DDA((x1+(l/2)) ,y1,(x1+l),(y1+(b/2)));
    DDA(x1 ,(y1+(b/2)),(x1+(l/2)),(y1+b));
    DDA(x1+(l/2) ,(y1+b),(x1+l),(y1+(b/2)));

    ui->label_8->setPixmap((QPixmap::fromImage(img)));
}







