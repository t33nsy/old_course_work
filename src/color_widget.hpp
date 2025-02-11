#ifndef COLOR_WIDGET_H
#define COLOR_WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QImage>
namespace Ui {
class Color_widget;
}

class Color_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Color_widget(QWidget *parent = nullptr);
    ~Color_widget();
    QColor get_color();
    void closeEvent(QCloseEvent *event);
private:
    Ui::Color_widget *ui;
    QImage img = QImage("auto-gen-palette.png");
    int r = 0, g = 0, b = 0, val = 0;
signals:
    void sgnClose(QColor col);
protected:
    void mouseMoveEvent(QMouseEvent *event);
private slots:
    void on_verticalSlider_valueChanged(int value);
    void on_pushButton_clicked();
};

#endif // COLOR_WIDGET_H
