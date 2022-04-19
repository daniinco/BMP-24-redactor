#pragma once

#include "string"
#include "vector"
#include "../bmp_picture.h"

class Filter {
public:
    virtual void apply_filter(BMP& bmp)=0;
};





