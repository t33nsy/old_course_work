#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <ctime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // QPixmap q("D:/projects/oop_course_work/tests/another.bmp");
    QPixmap aut("author.png");
    ui->author->setPixmap(aut.scaled( ui->author->width(), ui->author->height(), Qt::KeepAspectRatio));
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->lineEdit, SIGNAL(returnPressed()), ui->label_pic, SLOT(update()));
    connect(ui->comboBox, SIGNAL(activated(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));
    // connect(ui->comboBox, SIGNAL(on_comboBox_activated(int)), ui->rect_widget, SLOT(setVisible(bool)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->label, SLOT(setNum(int)));
    disconnect(ui->lineEdit, SIGNAL(returnPressed()), ui->label_pic, SLOT(update()));
    connect(ui->pushButton, SIGNAL(clicked()), ui->label_pic, SLOT(update()));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->color_show, SLOT(update()));
    // connect(ui->circ_isfill, SIGNAL(on_circ_isfill_stateChanged(int), ui->stackedWidget_2, SLOT(setCurrentIndex(int)));
    // ui->pushButton_4->hide();
    ui->frame_2->setMouseTracking(true);
    ui->label_41->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString text = ui->lineEdit->text();
    QPixmap q(text);
    input_filename = strdup((char*)text.toStdString().c_str());
    ui->label_pic->setPixmap(q.scaled(ui->label_pic->width(), ui->label_pic->height(), Qt::KeepAspectRatio));
    ui->label_4->setText(text);
}

void MainWindow::activated(int a){
    ui->stackedWidget->setCurrentIndex(a);
    std::cout<<a;
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::information(NULL, QObject::tr("afafg"), tr("asdgasf"));
}


void MainWindow::on_pattern_activated(int index)
{
    if(index==1){
        ui->stackedWidget_4->setCurrentIndex(1);
    }else{
        ui->stackedWidget_4->setCurrentIndex(0);
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    if(strcmp(input_filename, "nothing")==0) input_filename = strdup((char *)ui->lineEdit->text().toStdString().c_str());

    // rotate_leftUp.first = ui->rlu1->value(), rotate_leftUp.second = ui->rlu2->value();
    // rotate_rightDown.first = ui->rrd1->value(), rotate_rightDown.second = ui->rrd2->value();
    angle = ui->angle->currentText().toInt();

    QString forOutput = ui->lineEdit_5->text();
    output_filename= strdup((char*)forOutput.toStdString().c_str());

    if(strstr(input_filename, ".bmp")!=nullptr) {
        change_all1();
        Bmp input(input_filename);
        if(full) input.rotate_image(std::pair<int,int>{0,0}, std::pair<int,int>{INT_MAX, INT_MAX}, angle);
        else input.rotate_image(rotate_leftUp, rotate_rightDown, angle);
        input.save(output_filename);
    }else {
        change_all2();
        Bmp input;
        QMessageBox::warning(NULL, QObject::tr("You have not accepted your input file"), tr("because of disappendance of input file, I created white image width 1920x1080 resolution and in scope of"
                                                                                            " rotate it was so useless, be careful, please."));

        if(full) input.rotate_image(std::pair<int,int>{0,0}, std::pair<int,int>{INT_MAX, INT_MAX}, angle);
        else input.rotate_image(rotate_leftUp, rotate_rightDown, angle);
        input.save(output_filename);
    }
    // std::cout<<output_filename<<std::endl;
    // std::cout<<input_filename<<std::endl;

    QPixmap q(output_filename);
    ui->label_pic->setPixmap(q.scaled(ui->label_pic->width(), ui->label_pic->height(), Qt::KeepAspectRatio));
    ui->label_4->setText(output_filename);
    input_filename = strdup(output_filename);
}

void MainWindow::change_all1(){
    QPixmap q(input_filename);
    padX = q.width()%16;
    padY = q.height()%9;
    ui->rlu1->setValue((ui->rlu1->value())*q.width()/wikoeff - abs(q.width()-960)/(2*wikoeff));
    ui->rrd1->setValue((ui->rrd1->value())*q.width()/wikoeff - abs(q.width()-960)/(2*wikoeff));
    ui->rlu2->setValue((ui->rlu2->value())*q.height()/hekoeff + abs(q.height()-540)/(2*hekoeff));
    ui->rrd2->setValue((ui->rrd2->value())*q.height()/hekoeff - abs(q.height()-540)/(2*hekoeff));
    ui->lu1->setValue(ui->lu1->value()*q.width()/wikoeff);
    ui->rd1->setValue(ui->rd1->value()*q.width()/wikoeff);
    ui->lu2->setValue(ui->lu2->value()*q.height()/hekoeff);
    ui->rd2->setValue(ui->rd2->value()*q.height()/hekoeff);
    ui->circ_center1->setValue(ui->circ_center1->value()*q.width()/wikoeff);
    ui->circ_center2->setValue(ui->circ_center2->value()*q.height()/hekoeff);
    // ui->circ_radius->setValue(std::min((xEnd-xStart+1)/2, (yEnd-yStart+1)/2));
    if(xEnd-xStart+1<yEnd-yStart+1){
        ui->circ_radius->setValue((xEnd-xStart+1)/2);
    }else ui->circ_radius->setValue((yEnd-yStart+1)/2);
    std::cout<<std::min((xEnd-xStart+1)/2, (yEnd-yStart+1)/2)<<std::endl;
    wikoeff = q.width();
    hekoeff = q.height();
    leftUp.first = ui->lu1->value(), leftUp.second = ui->lu2->value();
    rightDown.first = ui->rd1->value(), rightDown.second = ui->rd2->value();
    rotate_leftUp.first = ui->rlu1->value(), rotate_leftUp.second = ui->rlu2->value();
    rotate_rightDown.first = ui->rrd1->value(), rotate_rightDown.second = ui->rrd2->value();
    center.first = ui->circ_center1->value(), center.second = ui->circ_center2->value();
    radius = ui->circ_radius->value();
}

void MainWindow::change_all2(){
    QPixmap q(output_filename);
    wikoeff = q.width();
    hekoeff = q.height();
    ui->lu1->setValue(xStart*wikoeff/960);
    ui->lu2->setValue((yStart)*hekoeff/540);
    ui->rd1->setValue(xEnd*wikoeff/960);
    ui->rd2->setValue((yEnd)*hekoeff/540);
    ui->circ_center1->setValue((xStart+xEnd)/2*wikoeff/960);
    ui->circ_center2->setValue((yEnd+yStart)/2*hekoeff/540);
    ui->rlu1->setValue(xStart*wikoeff/960);
    ui->rlu2->setValue((yStart)*hekoeff/540);
    ui->rrd1->setValue(xEnd*wikoeff/960);
    ui->rrd2->setValue((yEnd)*hekoeff/540);
    leftUp.first = ui->lu1->value(), leftUp.second = ui->lu2->value();
    rightDown.first = ui->rd1->value(), rightDown.second = ui->rd2->value();
    ui->circ_radius->setValue(std::min((xEnd-xStart+1)/2, (yEnd-yStart+1)/2));
    center.first = ui->circ_center1->value(), center.second = ui->circ_center2->value();
    std::cout<<std::min((xEnd-xStart+21)/2, (yEnd-yStart+121)/2)<<std::endl;
    radius = ui->circ_radius->value();
    rotate_leftUp.first = ui->rlu1->value(), rotate_leftUp.second = ui->rlu2->value();
    rotate_rightDown.first = ui->rrd1->value(), rotate_rightDown.second = ui->rrd2->value();
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    full = arg1;
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QMainWindow::mouseMoveEvent(event);
    ui->label_41->setGeometry(xStart, yStart, event->position().x()-10-xStart+1, event->position().y()-120-yStart+1);
}

void MainWindow::mousePressEvent(QMouseEvent * e){
    xStart = e->pos().x() - 10, yStart = e->pos().y() - 120;
        switch(ui->comboBox->currentIndex()){
        default:
            ui->lu1->setValue(xStart*wikoeff/960);
            ui->lu2->setValue((yStart-10)*hekoeff/540);
            ui->rlu1->setValue(xStart*wikoeff/960);
            ui->rlu2->setValue((yStart-10)*hekoeff/540);
            ui->label_41->setVisible(true);
            break;

        }
        wi = 1, he =1;
        ui->label_41->setGeometry(xStart, yStart,1,1);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e){
    xEnd = (e->pos().x()-10), yEnd = (e->pos().y()-120);
        ui->rd1->setValue(xEnd*wikoeff/960);
        ui->rd2->setValue((yEnd-10)*hekoeff/540);
        ui->rrd1->setValue(xEnd*wikoeff/960);
        ui->rrd2->setValue((yEnd-10)*hekoeff/540);
        ui->circ_center1->setValue(((xEnd + xStart)/2)*wikoeff/960);
        ui->circ_center2->setValue(((yEnd + yStart - 20)/2)*hekoeff/540);
        ui->circ_radius->setValue(std::min((xEnd-xStart+1)/2, (yEnd-yStart+1)/2));
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, tr("Open .bmp file"), "C:/Users/*/Images", tr("Image Files (*.bmp)"));
    if(fileName!=nullptr){
        input_filename = strdup(fileName.toStdString().c_str());
        ui->lineEdit->setText(fileName);
        QPixmap q(fileName);
        ui->label_pic->setPixmap(q.scaled(ui->label_pic->width(), ui->label_pic->height(), Qt::KeepAspectRatio));
    }
}


void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, tr("Open .bmp file"), "result", tr("Image Files (*.bmp)"));
    if(fileName!=nullptr){
        output_filename = strdup(fileName.toStdString().c_str());
        if(input_filename!="nothing"){
            Bmp q(input_filename);
            q.save(output_filename);
        }
        ui->lineEdit_3->setText(fileName);
    }
}


void MainWindow::on_actionHelp_triggered()
{
    QMessageBox *q = new QMessageBox;
    q->setInformativeText("Info");
    print_help(q);
    q->setMinimumHeight(540);
    q->setMinimumWidth(360);
    q->setWindowTitle("Help me");
    q->setDefaultButton(QMessageBox::Ok);
    q->exec();
}

void MainWindow::on_actionChoose_color_triggered()
{
    color_widget.show();
    connect(&color_widget, &Color_widget::sgnClose, this, &MainWindow::color_widget_close);
}

void MainWindow::color_widget_close(QColor col){
    r = col.red(), g = col.green(), b = col.blue();
    circ_r = col.red(), circ_g = col.green(), circ_b = col.blue();
    orn_r = col.red(), orn_g = col.green(), orn_b = col.blue();
    ui->color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(r).arg(g).arg(b));
    ui->circ_color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(circ_r).arg(circ_g).arg(circ_b));
    ui->ornament_col_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(orn_r).arg(orn_g).arg(orn_b));
    ui->spinBox->setValue(r);
    ui->spinBox_2->setValue(g);
    ui->spinBox_3->setValue(b);
    ui->circ_color_r->setValue(r);
    ui->circ_color_g->setValue(g);
    ui->circ_color_b->setValue(b);
    ui->ornament_red->setValue(r);
    ui->ornament_green->setValue(g);
    ui->ornament_blue->setValue(b);
    disconnect(&color_widget, &Color_widget::sgnClose, this, &MainWindow::color_widget_close);
}

void MainWindow::on_actionChoose_fill_color_triggered()
{
    fill_color_widget.show();
    connect(&fill_color_widget, &Color_widget::sgnClose, this, &MainWindow::fill_color_widget_close);
}

void MainWindow::fill_color_widget_close(QColor col){
    rF = col.red(), gF = col.green(), bF = col.blue();
    circ_rF = col.red(), circ_gF = col.green(), circ_bF = col.blue();
    ui->fillcolor_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(r).arg(g).arg(b));
    ui->circ_fill_color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(circ_rF).arg(circ_gF).arg(circ_bF));
    ui->spinBox_4->setValue(rF);
    ui->spinBox_5->setValue(gF);
    ui->spinBox_6->setValue(bF);
    ui->circ_color_rF->setValue(rF);
    ui->circ_colorgF->setValue(gF);
    ui->circ_color_bF->setValue(bF);
    disconnect(&fill_color_widget, &Color_widget::sgnClose, this, &MainWindow::fill_color_widget_close);
}
