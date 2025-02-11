QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    circle_options.cpp \
    color_widget.cpp \
    main.cpp \
    mainwindow.cpp \
    additional_funcs.cpp \
    drawing_funcs.cpp \
    ornament_options.cpp \
    rectangle_options.cpp \
    rotate_func.cpp

HEADERS += \
    circle_options.hpp \
    color_widget.hpp \
    mainwindow.hpp \
    additional_funcs.hpp \
    drawing_funcs.hpp \
    options.hpp \
    ornament_options.hpp \
    rectangle_options.hpp \
    rotate_func.hpp \
    structuresDefinition.hpp

FORMS += \
    color_widget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recource.qrc
