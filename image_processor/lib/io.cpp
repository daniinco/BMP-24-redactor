#include "io.h"
#include "iostream"
#include "stdexcept"

Reader::Reader(const std::string& file_name) : file_name_(file_name) {}

int Reader::read_int_from_some_bytes(int bytes_count, std::ifstream& in) {
    int result = 0;
    for (int i = 0; i < bytes_count; ++i) {
        int ch = static_cast<int>(in.get());
        ch = ch << (i * 8);
        result += static_cast<int>(ch);
    }
    return result;
}

void Reader::skip_some_bytes(int bytes_count, std::ifstream& in) {
    in.ignore(bytes_count);
}

Color Reader::read_pixel(std::ifstream &in) {
    int red = in.get();
    int green = in.get();
    int blue = in.get();
    Color pix(blue, green, red);
    return pix;
}

BMP Reader::read_from_file() {
    std::ifstream in(file_name_, std::ios::in | std::ios::binary);
    int buffer1 = in.get();
    int buffer2 = in.get();
    if (buffer1 != 'B' || buffer2 != 'M') {
        throw std::invalid_argument("wrong input file");
    }
    size_t size = read_int_from_some_bytes(4, in);
    skip_some_bytes(4, in);
    buffer1 = read_int_from_some_bytes(4, in);
    if (buffer1 != 54) {
        throw std::invalid_argument("wrong input file");
    }
    buffer1 = read_int_from_some_bytes(4, in);
    if (buffer1 != 40) {
        throw std::invalid_argument("wrong input file");
    }
    size_t width = read_int_from_some_bytes(4, in);
    size_t height = read_int_from_some_bytes(4, in);
    buffer1 = read_int_from_some_bytes(2, in);
    if (buffer1 != 1) {
        throw std::invalid_argument("wrong input file");
    }
    buffer1 = read_int_from_some_bytes(2, in);
    if (buffer1 != 24) {
        throw std::invalid_argument("wrong type of bmp");
    }
    buffer1 = read_int_from_some_bytes(4, in);
    if (buffer1 != 0) {
        throw std::invalid_argument("compressed bmp");
    }
    skip_some_bytes(4, in);
    int x_pels_per_meter = read_int_from_some_bytes(4, in);
    int y_pels_per_meter = read_int_from_some_bytes(4, in);
    skip_some_bytes(8, in);
    BMP result = BMP(x_pels_per_meter, y_pels_per_meter);
    std::vector<std::vector<Color>> pixels;
    for (size_t i = 0; i < height; ++i) {
        std::vector<Color> row;
        for (size_t j = 0; j < width; ++j) {
            row.push_back(read_pixel(in));
        }
        pixels.push_back(row);
    }
    skip_some_bytes((size - 54) % 3, in);
    if (in.eof()) {
        throw std::invalid_argument("wrong input file");
    }
    skip_some_bytes(1, in);
    if (in.good()) {
        throw std::invalid_argument("wrong input file");
    }
    result.set_pixels(pixels);
    return result;
}

Writer::Writer(const std::string& file_name) : file_name_(file_name) {}

void Writer::write_int_in_some_bytes(int bytes_count, int wrote_int, std::ofstream& out) {
    for (int i = 0; i < bytes_count; ++i) {
        out.put(wrote_int % 256);
        wrote_int -= (wrote_int % 256);
        wrote_int /= 256;
    }
}

void Writer::write_pixel(const Color& pix, std::ofstream& out) {
    out.put(pix.get_canals().blue);
    out.put(pix.get_canals().green);
    out.put(pix.get_canals().red);
}

void Writer::write_in_file(const BMP& bmp) {
    std::ofstream out(file_name_, std::ios::out | std::ios::binary);
    out.put('B');
    out.put('M');
    size_t width = bmp.get_sizes().first;
    size_t height = bmp.get_sizes().second;
    int size = 54 + width * height * 3;
    write_int_in_some_bytes(4, size, out);
    write_int_in_some_bytes(4, 0, out);
    write_int_in_some_bytes(4, 54, out);
    write_int_in_some_bytes(4, 40, out);
    write_int_in_some_bytes(4, width, out);
    write_int_in_some_bytes(4, height, out);
    write_int_in_some_bytes(2, 1, out);
    write_int_in_some_bytes(2, 24, out);
    write_int_in_some_bytes(8, 0, out);
    write_int_in_some_bytes(4, bmp.get_pells_per_meter().first, out);
    write_int_in_some_bytes(4, bmp.get_pells_per_meter().first, out);
    write_int_in_some_bytes(8, 0, out);
    auto pixels = bmp.get_pixels();
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            write_pixel(pixels[i][j], out);
        }
        write_int_in_some_bytes(width % 4, 0, out);
    }
}