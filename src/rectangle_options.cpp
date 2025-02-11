#include "rectangle_options.hpp"


void MainWindow::valueChanged(int a){
    ui->label->setNum(a);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    thickness = value;
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    fill = arg1;
    ui->stackedWidget_3->setCurrentIndex((ui->stackedWidget_3->currentIndex()+1)%2);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    r = arg1;
    ui->color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(r).arg(g).arg(b));
}

void MainWindow::on_spinBox_textChanged(const QString &arg1)
{
    r = arg1.toInt();
    ui->color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(r).arg(g).arg(b));
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    g = arg1;
    ui->color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(r).arg(g).arg(b));
}

void MainWindow::on_spinBox_2_textChanged(const QString &arg1)
{
    g = arg1.toInt();
    ui->color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(r).arg(g).arg(b));
}

void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    b = arg1;
    ui->color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(r).arg(g).arg(b));
}

void MainWindow::on_spinBox_3_textChanged(const QString &arg1)
{
    b = arg1.toInt();
    ui->color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(r).arg(g).arg(b));
}

void MainWindow::on_spinBox_4_textChanged(const QString &arg1)
{
    rF = arg1.toInt();
    ui->fillcolor_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(rF).arg(gF).arg(bF));
}


void MainWindow::on_spinBox_4_valueChanged(int arg1)
{
    rF = arg1;
    ui->fillcolor_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(rF).arg(gF).arg(bF));
}


void MainWindow::on_spinBox_5_textChanged(const QString &arg1)
{
    gF = arg1.toInt();
    ui->fillcolor_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(rF).arg(gF).arg(bF));
}


void MainWindow::on_spinBox_5_valueChanged(int arg1)
{
    gF = arg1;
    ui->fillcolor_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(rF).arg(gF).arg(bF));
}


void MainWindow::on_spinBox_6_textChanged(const QString &arg1)
{
    bF = arg1.toInt();
    ui->fillcolor_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(rF).arg(gF).arg(bF));
}


void MainWindow::on_spinBox_6_valueChanged(int arg1)
{
    bF = arg1;
    ui->fillcolor_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(rF).arg(gF).arg(bF));
}

void MainWindow::on_pushButton_clicked()
{
    if(strcmp(input_filename, "nothing")==0) input_filename = strdup((char *)ui->lineEdit->text().toStdString().c_str());
    color = std::to_string(r) + "." + std::to_string(g) + "." + std::to_string(b);

    fillColor = std::to_string(rF) + "." + std::to_string(gF) + "." + std::to_string(bF);


    QString forOutput = ui->lineEdit_3->text();
    output_filename= strdup((char*)forOutput.toStdString().c_str());
    if(strstr(input_filename, ".bmp")!=nullptr) {
        change_all1();
        Bmp input(input_filename);
        input.draw_rectangle(leftUp, rightDown, thickness, color.c_str(), fill, fillColor.c_str());
        input.save(output_filename);
    }else {
        Bmp input;
        QMessageBox::warning(NULL, QObject::tr("You have not accepted your input file"), tr("because of disappendance of input file, I created white image width 1920x1080 resolution"
                                                                                            " and drew rectangle on it."));
        input.draw_rectangle(leftUp, rightDown, thickness, color.c_str(), fill, fillColor.c_str());
        input.save(output_filename);
    }
    // std::cout<<output_filename<<std::endl;
    // std::cout<<input_filename<<std::endl;
    std::cout<<leftUp.first<<" "<<leftUp.second<<" "<<rightDown.first<<" "<<rightDown.second<<" "<<thickness<<" "<<color.c_str()<<" "<< fill<<" "<<fillColor.c_str()<<std::endl;


    QPixmap q(output_filename);
    ui->label_pic->setPixmap(q.scaled(ui->label_pic->width(), ui->label_pic->height(), Qt::KeepAspectRatio));
    ui->label_4->setText(output_filename);
    input_filename = strdup(output_filename);
}

