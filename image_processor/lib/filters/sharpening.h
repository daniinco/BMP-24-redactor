#pragma once

#include "filter.h"

class Sharpening : public Filter {
    void apply_filter(BMP &bmp) override;
};