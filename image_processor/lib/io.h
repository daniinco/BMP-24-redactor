#pragma once

#include "bmp_picture.h"
#include "fstream"
#include "iosfwd"
#include "istream"
#include "ostream"
#include "string"

class Reader {
public:
    Reader(const std::string& file_name);
    BMP read_from_file();

private:
    int read_int_from_some_bytes(int bytes_count, std::ifstream& in);
    void skip_some_bytes(int bytes_count, std::ifstream& in);
    Color read_pixel(std::ifstream& in);
    std::string file_name_;
};

class Writer {
public:
    Writer(const std::string& file_name);
    void write_in_file(const BMP& bmp);

private:
    void write_int_in_some_bytes(int bytes_count, int wrote_int, std::ofstream& out);
    void write_pixel(const Color& pix, std::ofstream& out);
    std::string file_name_;
};