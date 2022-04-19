#include "edge_detection.h"
#include "math.h"

EdgeDetection::EdgeDetection(float threshold) {
    threshold_ = std::round(threshold * 255);
}

void EdgeDetection::apply_filter(BMP& bmp) {
    Grayscale::apply_filter(bmp);
    auto pixels = bmp.get_pixels();
    std::vector<std::vector<Color>> new_pixels;
    size_t width = bmp.get_sizes().first;
    size_t height = bmp.get_sizes().second;
    for (size_t i = 0; i < height; ++i) {
        std::vector<Color> row;
        for (size_t j = 0; j < width; ++j) {
            std::vector<Color> colors;
            int grey = 0;
            grey += pixels[i][j].get_canals().red * 4;
            grey -= pixels[i][std::min(j + 1, width - 1)].get_canals().red;
            grey -= pixels[i][std::max(static_cast<int>(j - 1), 0)].get_canals().red;
            grey -= pixels[std::min(i + 1, height - 1)][j].get_canals().red;
            grey -= pixels[std::max(static_cast<int>(i - 1), 0)][j].get_canals().red;
            if (grey > threshold_) {
                row.push_back(Color(255, 255, 255));
            } else {
                row.push_back(Color(0, 0, 0));
            }
        }
        new_pixels.push_back(row);
    }
    bmp.set_pixels(new_pixels);
}