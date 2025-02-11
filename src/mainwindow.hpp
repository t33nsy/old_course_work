#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>
#include <iostream>
#include <string>
#include "structuresDefinition.hpp"
#include <QPixmap>
#include <fstream>
#include "additional_funcs.hpp"
#include <QMessageBox>
#include <QFileDialog>
#include "color_widget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_returnPressed();

    void activated(int index);

    void valueChanged(int);

    void on_pushButton_clicked();


    void on_horizontalSlider_valueChanged(int value);

    void on_checkBox_stateChanged(int arg1);

    void on_spinBox_textChanged(const QString &arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_2_textChanged(const QString &arg1);

    void on_spinBox_3_textChanged(const QString &arg1);

    void on_spinBox_4_textChanged(const QString &arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void on_spinBox_5_textChanged(const QString &arg1);

    void on_spinBox_5_valueChanged(int arg1);

    void on_spinBox_6_textChanged(const QString &arg1);

    void on_spinBox_6_valueChanged(int arg1);


    void on_circ_color_r_textChanged(const QString &arg1);

    void on_circ_color_g_textChanged(const QString &arg1);

    void on_circ_color_b_textChanged(const QString &arg1);

    void on_circ_color_r_valueChanged(int arg1);

    void on_circ_color_g_valueChanged(int arg1);

    void on_circ_color_b_valueChanged(int arg1);

    void on_circ_thick_valueChanged(int value);

    void on_circ_isfill_stateChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_circ_color_rF_textChanged(const QString &arg1);

    void on_circ_color_rF_valueChanged(int arg1);

    void on_circ_colorgF_textChanged(const QString &arg1);

    void on_circ_colorgF_valueChanged(int arg1);

    void on_circ_color_bF_textChanged(const QString &arg1);

    void on_circ_color_bF_valueChanged(int arg1);

    void on_ornament_red_textChanged(const QString &arg1);

    void on_ornament_red_valueChanged(int arg1);

    void on_ornament_green_textChanged(const QString &arg1);

    void on_ornament_green_valueChanged(int arg1);

    void on_ornament_blue_textChanged(const QString &arg1);

    void on_ornament_blue_valueChanged(int arg1);

    void on_ornament_thick_valueChanged(int value);

    void on_pushButton_3_clicked();


    void on_pushButton_4_clicked();

    void on_pattern_activated(int index);

    void on_pushButton_5_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void change_all1();

    void change_all2();

    void on_actionHelp_triggered();

    void on_actionChoose_color_triggered();

    void color_widget_close(QColor col);

    void fill_color_widget_close(QColor col);

    void on_actionChoose_fill_color_triggered();

private:
    Ui::MainWindow *ui;
    char *input_filename = (char *)"nothing", *output_filename = (char *)"out.bmp";
    int r = 0, g = 0, b = 0, rF = 0, gF = 0, bF = 0;
    std::pair<int,int> leftUp = {0,0}, rightDown = {0,0};
    uint32_t thickness = 1;
    std::string color, fillColor = "0.0.0";
    bool fill = false;

    int circ_r = 0, circ_g = 0, circ_b = 0, circ_rF = 0, circ_gF = 0, circ_bF = 0;
    uint32_t circ_thickness = 1, radius = 1;
    std::pair<int,int> center = {0,0};
    std::string circ_color, circ_fill_color = "0.0.0";
    bool circ_fill = false;

    int orn_r = 0, orn_g = 0, orn_b = 0;
    std::string pattern, orn_color;
    uint32_t orn_thickness = 1, orn_count = 1;

    std::pair<int,int> rotate_leftUp = {0,0}, rotate_rightDown = {0,0};
    int angle;
    bool full = false;
    int xStart, xEnd, yStart, yEnd, wi, he;
    int wikoeff = 1920, hekoeff = 1080;
    bool rect_was = false;
    int padX, padY;

    Color_widget color_widget;
    Color_widget fill_color_widget;
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent * e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
};
#endif // MAINWINDOW_HPP
