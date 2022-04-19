#pragma once

#include "filters/crop.h"
#include "filters/edge_detection.h"
#include "filters/filter.h"
#include "filters/gaussian_blur.h"
#include "filters/grayscale.h"
#include "filters/negative.h"
#include "filters/pixellate.h"
#include "filters/sharpening.h"
#include "memory"
#include "parser.h"
#include "vector"

std::vector<std::shared_ptr<Filter>> filters_factory(const std::vector<FilterDefinition>& filter_defs);