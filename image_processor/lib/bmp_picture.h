#pragma once

#include "color.h"
#include "string"
#include "vector"

class BMP {
public:
    BMP(int x_pels_per_meter, int y_pels_per_meter);
    std::vector<std::vector<Color>> get_pixels() const;
    void set_pixels(const std::vector<std::vector<Color>>& pixels);
    std::pair<size_t, size_t> get_sizes() const;
    std::pair<size_t, size_t> get_pells_per_meter() const;

private:
    size_t width_;
    size_t height_;
    int x_pels_per_meter_;
    int y_pels_per_meter_;
    std::vector<std::vector<Color>> pixels_;
};