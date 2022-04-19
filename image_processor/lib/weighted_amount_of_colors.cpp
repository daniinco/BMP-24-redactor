#include "weighted_amount_of_colors.h"

Color weighted_amount(const std::vector<Color>& colors, const std::vector<int>& weights) {
    int red_result = 0;
    int green_result = 0;
    int blue_result = 0;
    for (size_t i = 0; i < weights.size(); ++i) {
        red_result += weights[i] * colors[i].get_canals().red;
        green_result += weights[i] * colors[i].get_canals().green;
        blue_result += weights[i] * colors[i].get_canals().blue;
    }
    red_result = std::max(0, std::min(255, red_result));
    green_result = std::max(0, std::min(255, green_result));
    blue_result = std::max(0, std::min(255, blue_result));
    return Color(red_result, green_result, blue_result);
}