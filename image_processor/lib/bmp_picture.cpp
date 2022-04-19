#include "bmp_picture.h"

BMP::BMP(int x_pels_per_meter, int y_pels_per_meter)
: x_pels_per_meter_(x_pels_per_meter), y_pels_per_meter_(y_pels_per_meter) {}

std::vector<std::vector<Color>> BMP::get_pixels() const {
    return pixels_;
}

void BMP::set_pixels(const std::vector<std::vector<Color>>& pixels) {
    pixels_ = pixels;
    if (pixels.empty()) {
        width_ = 0;
        height_ = 0;
    } else {
        height_ = pixels.size();
        width_ = pixels[0].size();
    }
}

std::pair<size_t, size_t> BMP::get_sizes() const {
    return std::pair<size_t, size_t>(width_, height_);
}

std::pair<size_t, size_t> BMP::get_pells_per_meter() const {
    return std::pair<size_t, size_t>(x_pels_per_meter_, y_pels_per_meter_);
}