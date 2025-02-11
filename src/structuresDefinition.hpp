#ifndef COURSE_WORK_STRUCTURESDEFINITION_HPP
#define COURSE_WORK_STRUCTURESDEFINITION_HPP

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <fstream>

#pragma pack (push, 1)

typedef struct BitmapFileHeader {
    unsigned short signature;
    unsigned int fileSize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int pixelArrOffset;
} BitmapFileHeader;

typedef struct BitmapInfoHeader {
    unsigned int headerSize;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    unsigned int xPixelsPerMeter;
    unsigned int yPixelsPerMeter;
    unsigned int colorsInColorTable;
    unsigned int importantColorCount;
} BitmapInfoHeader;

typedef struct Rgb {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Rgb;
#pragma pack(pop)

class Bmp {
public:
    explicit
    Bmp(const char *filename); //defined in additional_funcs.cpp

    Bmp();

    ~Bmp(); //defined in additional_funcs.cpp

    void
    get_info(); //defined in additional_funcs.cpp

    void
    save(const char *output_filename); //defined in additional_funcs.cpp

    void
    draw_rectangle(std::pair<int, int> leftUp, std::pair<int, int> rightDown, unsigned int thickness, const char *color,
                   bool fill, const char *fillColor); //defined in drawing_funcs.cpp

    void
    draw_circle(std::pair<int, int> center, unsigned int radius, unsigned int thickness, const char *color,
                bool fill, const char *fillColor); //defined in drawing_funcs.cpp

    void
    drawOrnament(const char *pattern, const char *color, size_t thickness, size_t count); //defined in drawing_funcs.cpp

    void
    rotate_image(std::pair<int, int> leftUp, std::pair<int, int> rightDown, int angle); //defined in rotate_func.cpp

    void straight_angle(std::pair<int, int> leftUp, std::pair<int, int> rightDown); //defined in rotate_func.cpp

    void full_right_angle();

    void field_right_angle(std::pair<int, int> leftUp, std::pair<int, int> rightDown);

    void field_right_and_straight_angle(std::pair<int, int> leftUp, std::pair<int, int> rightDown);

    void check_coordinates(std::pair<int, int> &leftUp, std::pair<int, int> &rightDown);

    void one_color(int r, int g, int b);

    void draw_line(std::pair<int, int> leftUp, std::pair<int, int> rightDown, unsigned int thickness, const char *color);

    void koch(int x1, int y1, int x2, int y2, unsigned int thickness, const char *color, int count, int i);

    void draw_snowflake(std::pair<int, int> leftUp, std::pair<int, int> rightDown, unsigned int thickness, const char *color, int count);

private:
    BitmapFileHeader *header;
    BitmapInfoHeader *info;
    Rgb **data;
    int padding;
};

#endif //COURSE_WORK_STRUCTURESDEFINITION_HPP
