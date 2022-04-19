#include "math.h"
#include "pixellate.h"

Pixellate::Pixellate(int pixel_size) : pixel_size_(pixel_size) {}

Color Pixellate::calculate_average_in_square(const std::vector<std::vector<Color>>& pixels, size_t x, size_t y) {
    int red = 0;
    int green = 0;
    int blue = 0;
    size_t width = 0;
    size_t height = pixels.size();
    if (height != 0) {
        width = pixels.size();
    }
    Canals canals;
    int pixels_count = 0;
    for (int i = 0; i < pixel_size_; ++i) {
        for (int j = 0; j < pixel_size_; ++j) {
            if (x + i < height && y + j < width) {
                canals = pixels[x + i][y + j].get_canals();
                red += canals.red;
                green += canals.green;
                blue += canals.blue;
                pixels_count += 1;
            }
        }
    }
    red /= pixels_count;
    green /= pixels_count;
    blue /= pixels_count;
    return Color(red, green, blue);
}

void Pixellate::apply_filter(BMP& bmp) {
    auto pixels = bmp.get_pixels();
    size_t width = bmp.get_sizes().first;
    size_t height = bmp.get_sizes().second;
    size_t pseudo_width;
    if ((width % pixel_size_) == 0) {
        pseudo_width = width / pixel_size_;
    } else {
        pseudo_width = width / pixel_size_ + 1;
    }
    size_t pseudo_height;
    if ((height % pixel_size_) == 0) {
        pseudo_height = height / pixel_size_;
    } else {
        pseudo_height = height / pixel_size_ + 1;
    }
    std::vector<std::vector<Color>> pseudo_result;
    std::vector<Color> row;
    for (size_t i = 0; i < pseudo_height; ++i) {
        row = {};
        for (size_t j = 0; j < pseudo_width; ++j) {
            row.push_back(calculate_average_in_square(pixels, i * pixel_size_, j * pixel_size_));
        }
        pseudo_result.push_back(row);
    }
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            pixels[i][j] = pseudo_result[i / pixel_size_][j / pixel_size_];
        }
    }
    bmp.set_pixels(pixels);
}