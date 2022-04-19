#include "sharpening.h"
#include "../weighted_amount_of_colors.h"

void Sharpening::apply_filter(BMP& bmp) {
    auto pixels = bmp.get_pixels();
    std::vector<std::vector<Color>> new_pixels;
    size_t width = bmp.get_sizes().first;
    size_t height = bmp.get_sizes().second;
    for (size_t i = 0; i < height; ++i) {
        std::vector<Color> row;
        for (size_t j = 0; j < width; ++j) {
            std::vector<Color> colors;
            std::vector<int> weights = {5, -1, -1, -1, -1};
            colors.push_back(pixels[i][j]);
            colors.push_back(pixels[i][std::min(j + 1, width - 1)]);
            colors.push_back(pixels[i][std::max(static_cast<int>(j - 1), 0)]);
            colors.push_back(pixels[std::min(i + 1, height - 1)][j]);
            colors.push_back(pixels[std::max(static_cast<int>(i - 1), 0)][j]);
            row.push_back(weighted_amount(colors, weights));
        }
        new_pixels.push_back(row);
    }
    bmp.set_pixels(new_pixels);
}