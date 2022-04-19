#pragma once

#include "filter.h"

class GaussianBlur : public Filter {
public:
    GaussianBlur(float sigma);
    void apply_filter(BMP& bmp) override;

private:
    std::vector<float> gaussian_values_;
    int max_distance_;
};