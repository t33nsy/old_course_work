#include "color_widget.hpp"
#include "ui_color_widget.h"
#include <QImage>
#include <iostream>
#include <fstream>

Color_widget::Color_widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Color_widget)
{
    ui->setupUi(this);
    QPixmap q = QPixmap::fromImage(img);
    ui->label->setPixmap(q.scaled(ui->label->width(),ui->label->height(), Qt::IgnoreAspectRatio));
    ui->label_4->hide();
    ui->verticalSlider->setStyleSheet("background : rgb(0, 0, 0)");
}

Color_widget::~Color_widget()
{
    delete ui;
}

void Color_widget::mouseMoveEvent(QMouseEvent *event)
{
    // Color_widget::mouseMoveEvent(event);
    // QImage q("auto-gen-palette.png");
    int x = (event->pos().x()-10)*6, y = (event->pos().y()-10);
    if(x>=0 && x/6<256 && y>=0 && y<256){
        ui->label_4->show();
        ui->label_4->setGeometry(x/6+10, y+10, 5, 5);
        ui->label_4->setStyleSheet("background: rgb(0,0,0)");
        QColor color = QColor(img.pixel(x, y));
        r = color.red(), g = color.green(), b = color.blue();
        ui->label_2->setText(tr("R: %1\nG: %2\nB: %3").arg(r*val/100).arg(g*val/100).arg(b*val/100));
        ui->label_3->setStyleSheet(tr("background: rgb(%1, %2, %3)").arg(r*val/100).arg(g*val/100).arg(b*val/100));
        ui->verticalSlider->setStyleSheet(tr("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(%1, %2, %3, 255));").arg(r).arg(g).arg(b));
    }
}

void Color_widget::on_verticalSlider_valueChanged(int value)
{
    ui->label_2->setText(tr("R: %1\nG: %2\nB: %3").arg(r*value/100).arg(g*value/100).arg(b*value/100));
    ui->label_3->setStyleSheet(tr("background: rgb(%1, %2, %3)").arg(r*value/100).arg(g*value/100).arg(b*value/100));
    val = value;
    ui->verticalSlider->setStyleSheet(tr("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(%1, %2, %3, 255));").arg(r).arg(g).arg(b));
}

QColor Color_widget::get_color(){
    return QColor(r,g,b);
}

void Color_widget::closeEvent(QCloseEvent *event){
    emit sgnClose(QColor(r*val/100,g*val/100,b*val/100));
    event->accept();
}


void Color_widget::on_pushButton_clicked()
{
    this->close();
}

