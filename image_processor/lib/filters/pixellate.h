#pragma once

#include "filter.h"

class Pixellate : public Filter {
public:
    Pixellate(int pixel_size);
    Color calculate_average_in_square(const std::vector<std::vector<Color>>& pixels, size_t x, size_t y);
    void apply_filter(BMP& bmp) override;

private:
    int pixel_size_;
};