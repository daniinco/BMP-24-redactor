#include "crop.h"
#include "stdexcept"

Crop::Crop(size_t width, size_t height) : width_(width), height_(height) {
    if (width < 0 || height < 0) {
        throw std::invalid_argument("negative sizes");
    }
}

void Crop::apply_filter(BMP& bmp) {
    auto pixels = bmp.get_pixels();
    if (height_ < bmp.get_sizes().second) {
        pixels.erase(pixels.begin(), pixels.begin() + (bmp.get_sizes().second - height_));
    }
    if (width_ < bmp.get_sizes().first) {
        for (size_t i = 0; i < bmp.get_sizes().second; ++i) {
            pixels[i].resize(width_);
        }
    }
    bmp.set_pixels(pixels);
}