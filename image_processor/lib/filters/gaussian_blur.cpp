#include "gaussian_blur.h"
#include "math.h"
#include "vector"

GaussianBlur::GaussianBlur(float sigma) {
    std::vector<float> gaussian_values;
    float coef = (1 / sqrt(2 * M_PI * sigma * sigma));
    max_distance_ = std::ceil(sigma * 3);
    for (int i = 0; i < (max_distance_ + 1); ++i) {
        gaussian_values.push_back(coef * pow(M_E, (-1 * i * i / (2 * sigma * sigma))));
    }
    gaussian_values_ = gaussian_values;
}

void GaussianBlur::apply_filter(BMP &bmp) {
    auto pixels = bmp.get_pixels();
    std::vector<std::vector<FloatColor>> first_blur;
    size_t width = bmp.get_sizes().first;
    size_t height = bmp.get_sizes().second;
    std::vector<FloatColor> row;
    for (size_t i = 0; i < height; ++i) {
        row = {};
        for (size_t j = 0; j < width; ++j) {
            FloatColor pixel = FloatColor(0, 0, 0);
            for (int deviation = (max_distance_ * -1); deviation < max_distance_ + 1; ++deviation) {
                if (i + deviation >= 0 && i + deviation < height) {
                    pixel = pixel + (FloatColor(pixels[i + deviation][j]) * gaussian_values_[abs(deviation)]);
                }
            }
            row.push_back(pixel);
        }
        first_blur.push_back(row);
    }
    std::vector<std::vector<FloatColor>> second_blur;
    for (size_t i = 0; i < height; ++i) {
        row = {};
        for (size_t j = 0; j < width; ++j) {
            FloatColor pixel = FloatColor(0, 0, 0);
            for (int deviation = (max_distance_ * -1); deviation < max_distance_ + 1; ++deviation) {
                if (j + deviation >= 0 && j + deviation < width) {
                    pixel = pixel + (first_blur[i][j + deviation] * gaussian_values_[abs(deviation)]);
                }
            }
            row.push_back(pixel);
        }
        second_blur.push_back(row);
    }
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            pixels[i][j] = second_blur[i][j].transform_in_color();
        }
    }
    bmp.set_pixels(pixels);
}