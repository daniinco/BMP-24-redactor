#pragma once

#include "grayscale.h"

class EdgeDetection : public Grayscale {
public:
    EdgeDetection(float threshold);
    void apply_filter(BMP& bmp);

private:
    float threshold_ = 0.02;
};