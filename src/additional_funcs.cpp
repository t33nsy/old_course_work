#include "additional_funcs.hpp"

#include <iostream>
#include "mainwindow.hpp"
#include <QTranslator>
void swapRgb(Rgb *rgb, int red, int green, int blue) {
    rgb->red = (unsigned char) red;
    rgb->green = (unsigned char) green;
    rgb->blue = (unsigned char) blue;
}

void print_help(QMessageBox *q) {
    q->setText("<b>IMAGE FUNCTIONS HELP<\b>\n"
                "<n>LIST OF FUNCTIONS WITH FLAGS THAT THEY TAKE <\n>"
                " 1. Draw rectangle\n"
                "    Arguments of rectangle function: \n"
                "     set coordinates of left upper corner: "
                "as argument takes coordinates in format X.Y\n"
                "     set coordinates of right down corner:     as argument takes coordinates in format X.Y\n"
                "     set thickness of rectangle outline:       flag --thickness (or -t), as argument takes integer value greater than 0\n"
                "     set color of rectangle outline:           flag --color (or -c), as argument takes string in format 'RRR.GGG.BBB'\n"
                "     will rectangle be filled or not:          flag --fill (or -f), if flag is set, it will be filled else will not\n"
                "     color of filling if rectangle is filled:  flag --fill_color, as argument takes string in format 'RRR.GGG.BBB'\n"
                " 2. Draw ornament \n"
                "    Flags for ornament function: \n"
                "     choose pattern of drawn ornament:  flag --pattern (or -p), as argument takes one of following strings: 'rectangle', 'circle' or 'semicircles'\n"
                "     set color of ornament:             flag --color (or -c), as argument takes string in format 'RRR.GGG.BBB'\n"
                "     set thickness of ornament:         flag --thickness (or -t), argument - integer value greater than 0 (may be omitted if pattern is circle)\n"
                "     set count of pattern fragments:    flag --count, as argument takes integer greater than 0 (may be omitted if pattern is circle)\n"
                " 4. Draw circle \n"
                "    Flags for circle function: \n"
                "     set coordinates of circle's center:    flag --center, as argument takes coordinates in format X.Y\n"
                "     set radius of circle:                  flag --radius, as argument takes integer value greater than 0\n"
                "     set thickness of circle's outline:     flag --thickness (or -t), as argument takes integer value greater than 0\n"
                "     set color of circle's outline:         flag --color (or -c), as argument takes string in format 'RRR.GGG.BBB'\n"
                "     will circle be filled or not:          flag --fill (or -f), if flag is set, it will be filled else will not\n"
                 "     color of filling if circle is filled:  flag --fill_color, as argument takes string in format 'RRR.GGG.BBB'\n");
}

Bmp::Bmp(const char *filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << filename << " not found" << std::endl;
        exit(41);
    } else {
        this->header = new BitmapFileHeader;
        this->info = new BitmapInfoHeader;
        file.read(reinterpret_cast<char *>(this->header), sizeof(BitmapFileHeader));
        file.read(reinterpret_cast<char *>(this->info), sizeof(BitmapInfoHeader));
        if (header->signature != 0x4D42) {
            QMessageBox::warning(nullptr, "Course work", "Not a bitmap file\nExiting program");
            exit(41);
        }
        if (info->bitsPerPixel != 24) {
            QMessageBox::warning(nullptr, "Course work", "Not a 24-bit bitmap file\nExiting program");
            exit(41);
        }
    }
    data = new Rgb *[this->info->height];
    padding = (int)(4 - this->info->width * 3 % 4)%4;
    for (size_t i = 0; i < this->info->height; i++) {
        data[i] = new Rgb[this->info->width];
        file.read(reinterpret_cast<char *>(data[i]), (this->info->width) * sizeof(Rgb));
        file.ignore(padding);
    }
    file.close();
}

void Bmp::get_info() {
    std::cout << "Signature: " << header->signature << std::endl;
    std::cout << "File size: " << header->fileSize << std::endl;
    std::cout << "Reserved 1: " << header->reserved1 << std::endl;
    std::cout << "Reserved 2: " << header->reserved2 << std::endl;
    std::cout << "Bitmap offset: " << header->pixelArrOffset << std::endl;
    std::cout << "Header size: " << info->headerSize << std::endl;
    std::cout << "Width: " << info->width << std::endl;
    std::cout << "Height: " << info->height << std::endl;
    std::cout << "Planes: " << info->planes << std::endl;
    std::cout << "Bits per pixel:" << info->bitsPerPixel << std::endl;
    std::cout << "Compression: " << info->compression << std::endl;
    std::cout << "Image size: " << info->imageSize << std::endl;
    std::cout << "X pixels per meter: " << info->xPixelsPerMeter << std::endl;
    std::cout << "Y pixels per meter: " << info->yPixelsPerMeter << std::endl;
    std::cout << "Colors used: " << info->colorsInColorTable << std::endl;
    std::cout << "Important colors: " << info->importantColorCount << std::endl;
}

Bmp::~Bmp() {
    for (size_t i = 0; i < this->info->height; i++) {
        delete[] data[i];
    }
    delete[] data;
    delete info;
    delete header;
}

void Bmp::save(const char *output_filename) {
    std::ofstream file(output_filename, std::ios::binary | std::ios::out);
    file.write(reinterpret_cast<const char *>(this->header), sizeof(BitmapFileHeader));
    file.write(reinterpret_cast<const char *>(this->info), sizeof(BitmapInfoHeader));
    for (size_t i = 0; i < this->info->height; i++) {
        file.write(reinterpret_cast<const char *>(data[i]), (this->info->width) * sizeof(Rgb));
        file.write("0", padding);
    }
    file.close();
}

void Bmp::one_color(int r, int g, int b){
    for(int i = 0;i<info->height;++i){
        for(int j = 0; j<info->width; ++j) swapRgb(&(data[i][j]), r,g,b);
    }
}

void show_color(int r, int g, int b, const char * file){
    Bmp bmp(file);
    bmp.one_color(r,g,b);
    bmp.save(file);
}
Bmp::Bmp(){
    header = new BitmapFileHeader;
    info = new BitmapInfoHeader;
    header->pixelArrOffset = 54, header->signature = 0x4D42, header->fileSize = 54 + 1920*1080*3, header->reserved1 = 0, header->reserved2 = 0;
    info->width = 1920, info->height = 1080, info->bitsPerPixel = 24, info->imageSize = 1920*1080*3, info->compression= 0, info->colorsInColorTable = 0, info->planes = 1;
    info->xPixelsPerMeter = 3780, info->yPixelsPerMeter = 3780, info->headerSize = 40;
    padding = 0;
    data = new Rgb*[1080];
    for(int i = 0; i<1080; i++){
        data[i] = new Rgb[1920];
        for(int j = 0; j<1920; j++){
            data[i][j].red = (unsigned char)255;
            data[i][j].green = (unsigned char)255;
            data[i][j].blue = (unsigned char)255;
        }
    }
}
