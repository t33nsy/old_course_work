#include "circle_options.hpp"
void MainWindow::on_circ_color_r_textChanged(const QString &arg1)
{
    circ_r = arg1.toInt();
    ui->circ_color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(circ_r).arg(circ_g).arg(circ_b));
}


void MainWindow::on_circ_color_g_textChanged(const QString &arg1)
{
    circ_g = arg1.toInt();
    ui->circ_color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(circ_r).arg(circ_g).arg(circ_b));
}


void MainWindow::on_circ_color_b_textChanged(const QString &arg1)
{
    circ_b = arg1.toInt();
    ui->circ_color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(circ_r).arg(circ_g).arg(circ_b));
}


void MainWindow::on_circ_color_r_valueChanged(int arg1)
{
    circ_r = arg1;
    ui->circ_color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(circ_r).arg(circ_g).arg(circ_b));
}


void MainWindow::on_circ_color_g_valueChanged(int arg1)
{
    circ_g = arg1;
    ui->circ_color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(circ_r).arg(circ_g).arg(circ_b));
}


void MainWindow::on_circ_color_b_valueChanged(int arg1)
{
    circ_b = arg1;
    ui->circ_color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(circ_r).arg(circ_g).arg(circ_b));
}


void MainWindow::on_circ_thick_valueChanged(int value)
{
    ui->label_27->setNum(value);
    circ_thickness = value;
}


void MainWindow::on_circ_isfill_stateChanged(int arg1)
{
    circ_fill = arg1;
    ui->stackedWidget_2->setCurrentIndex((ui->stackedWidget_2->currentIndex()+1)%2);
}

void MainWindow::on_circ_color_rF_textChanged(const QString &arg1)
{
    circ_rF = arg1.toInt();
    ui->circ_fill_color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(circ_rF).arg(circ_gF).arg(circ_bF));
}


void MainWindow::on_circ_color_rF_valueChanged(int arg1)
{
    circ_rF = arg1;
    ui->circ_fill_color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(circ_rF).arg(circ_gF).arg(circ_bF));
}


void MainWindow::on_circ_colorgF_textChanged(const QString &arg1)
{
    circ_gF = arg1.toInt();
    ui->circ_fill_color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(circ_rF).arg(circ_gF).arg(circ_bF));
}


void MainWindow::on_circ_colorgF_valueChanged(int arg1)
{
    circ_gF = arg1;
    ui->circ_fill_color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(circ_rF).arg(circ_gF).arg(circ_bF));
}


void MainWindow::on_circ_color_bF_textChanged(const QString &arg1)
{
    circ_bF = arg1.toInt();
    ui->circ_fill_color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(circ_rF).arg(circ_gF).arg(circ_bF));
}


void MainWindow::on_circ_color_bF_valueChanged(int arg1)
{
    circ_bF = arg1;
    ui->circ_fill_color_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(circ_rF).arg(circ_gF).arg(circ_bF));
}


void MainWindow::on_pushButton_2_clicked()
{
    if(strcmp(input_filename, "nothing")==0) input_filename = strdup((char *)ui->lineEdit->text().toStdString().c_str());

    circ_color = std::to_string(circ_r) + "." + std::to_string(circ_g) + "." + std::to_string(circ_b);
    circ_fill_color = std::to_string(circ_rF) + "." + std::to_string(circ_gF) + "." + std::to_string(circ_bF);
    circ_thickness = ui->circ_thick->value();
    output_filename = strdup((char *)ui->lineEdit_2->text().toStdString().c_str());

    if(strstr(input_filename, ".bmp")!=nullptr) {
        change_all1();
        Bmp input(input_filename);
        std::cout<<center.first<<" "<<center.second<<std::endl;
        input.draw_circle(center, radius, circ_thickness, circ_color.c_str(), circ_fill, circ_fill_color.c_str());
        input.save(output_filename);
    }else {
        change_all2();
        Bmp input;
        QMessageBox::warning(NULL, QObject::tr("You have not accepted your input file"), tr("because of disappendance of input file, I created white image width 1920x1080 resolution and"
                                                                                            " drew circle on it."));
        std::cout<<center.first<<" "<<center.second<<std::endl;
        input.draw_circle(center, radius, circ_thickness, circ_color.c_str(), circ_fill, circ_fill_color.c_str());
        input.save(output_filename);
    }

    QPixmap q(output_filename);
    ui->label_pic->setPixmap(q.scaled(ui->label_pic->width(), ui->label_pic->height(), Qt::KeepAspectRatio));
    ui->label_4->setText(output_filename);

    input_filename = strdup(output_filename);
}

