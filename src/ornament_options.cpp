#include "ornament_options.hpp"


void MainWindow::on_ornament_red_textChanged(const QString &arg1)
{
    orn_r = arg1.toInt();
    ui->ornament_col_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(orn_r).arg(orn_g).arg(orn_b));
}


void MainWindow::on_ornament_red_valueChanged(int arg1)
{
    orn_r = arg1;
    ui->ornament_col_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(orn_r).arg(orn_g).arg(orn_b));
}


void MainWindow::on_ornament_green_textChanged(const QString &arg1)
{
    orn_g = arg1.toInt();
    ui->ornament_col_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(orn_r).arg(orn_g).arg(orn_b));
}


void MainWindow::on_ornament_green_valueChanged(int arg1)
{
    orn_g = arg1;
    ui->ornament_col_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(orn_r).arg(orn_g).arg(orn_b));
}


void MainWindow::on_ornament_blue_textChanged(const QString &arg1)
{
    orn_b = arg1.toInt();
    ui->ornament_col_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(orn_r).arg(orn_g).arg(orn_b));
}


void MainWindow::on_ornament_blue_valueChanged(int arg1)
{
    orn_b = arg1;
    ui->ornament_col_show->setStyleSheet(QString("background: rgb(%1, %2, %3)").arg(orn_r).arg(orn_g).arg(orn_b));
}


void MainWindow::on_ornament_thick_valueChanged(int value)
{
    ui->orn_show_th->setNum(value);
    orn_thickness = value;
}


void MainWindow::on_pushButton_3_clicked()
{
    if(strcmp(input_filename, "nothing")==0) input_filename = strdup((char *)ui->lineEdit->text().toStdString().c_str());

    orn_color = std::to_string(orn_r) + "." + std::to_string(orn_g) + "." + std::to_string(orn_b);
    orn_thickness = ui->ornament_thick->value();
    orn_count = ui->ornament_count->value();

    int tmp = ui->pattern->currentIndex();
    switch(tmp){
    case(0):{
        pattern = "rectangle";
        break;
    }
    case(1):{
        pattern = "circle";
        break;
    }
    case(2):{
        pattern = "semicircles";
        break;
    }
    case(3):{
        pattern = "koch";
        break;
    }
    }

    output_filename = strdup((char *)ui->lineEdit_2->text().toStdString().c_str());

    if(strstr(input_filename, ".bmp")!=nullptr) {
        Bmp input(input_filename);
        input.drawOrnament(pattern.c_str(), orn_color.c_str(), orn_thickness, orn_count);
        input.save(output_filename);
    }else {
        Bmp input;
        QMessageBox::warning(NULL, QObject::tr("You have not accepted your input file"), tr("because of disappendance of input file, I created white image width 1920x1080 resolution and drew"
                                                                                            " ornament on it"));
        input.drawOrnament(pattern.c_str(), orn_color.c_str(), orn_thickness, orn_count);
        input.save(output_filename);
    }
    QPixmap q(output_filename);
    ui->label_pic->setPixmap(q.scaled(ui->label_pic->width(), ui->label_pic->height(), Qt::KeepAspectRatio));
    ui->label_4->setText(output_filename);

    input_filename = strdup(output_filename);
    // QMessageBox::information(NULL, QObject::tr("Function [draw_ornament]"),
                             // tr("Function done without errors, you can see\n result in programm window\n and it was saved in"));
}
