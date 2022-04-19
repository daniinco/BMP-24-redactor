#include "negative.h"
#include "string"

void Negative::apply_filter(BMP& bmp) {
    auto pixels = bmp.get_pixels();
    size_t width = bmp.get_sizes().first;
    size_t height = bmp.get_sizes().second;
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            int red = pixels[i][j].get_canals().red;
            int green = pixels[i][j].get_canals().green;
            int blue = pixels[i][j].get_canals().blue;
            pixels[i][j].set_canals(Canals{255 - red, 255 - green, 255 - blue});
        }
    }
    bmp.set_pixels(pixels);
}