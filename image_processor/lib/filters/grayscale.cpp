#include "cmath"
#include "grayscale.h"

void Grayscale::apply_filter(BMP& bmp) {
    auto pixels = bmp.get_pixels();
    size_t width = bmp.get_sizes().first;
    size_t height = bmp.get_sizes().second;
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            int red = pixels[i][j].get_canals().red;
            int green = pixels[i][j].get_canals().green;
            int blue = pixels[i][j].get_canals().blue;
            int grey = std::round(red * 0.299 + green * 0.587 + blue * 0.114);
            pixels[i][j].set_canals(Canals{grey, grey, grey});
        }
    }
    bmp.set_pixels(pixels);
}