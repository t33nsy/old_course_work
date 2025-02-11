#ifndef COURSE_WORK_ADDITIONAL_FUNCS_HPP
#define COURSE_WORK_ADDITIONAL_FUNCS_HPP

#include "structuresDefinition.hpp"
#include <QPushButton>
#include <QMessageBox>

void swapRgb(Rgb *rgb, int red, int green, int blue);

void print_help(QMessageBox *q);

void show_color(int r, int g, int b, const char * file);
#endif //COURSE_WORK_ADDITIONAL_FUNCS_HPP
