#pragma once

#include "filter.h"

class Negative : public Filter {
public:
    void apply_filter(BMP& bmp) override;
};