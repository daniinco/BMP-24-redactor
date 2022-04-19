#pragma once

#include "filter.h"

class Grayscale : public Filter {
public:
    void apply_filter(BMP& bmp) override;
};