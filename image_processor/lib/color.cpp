#include "color.h"
#include "math.h"

Color::Color(int red, int green, int blue) : red_(red), green_(green), blue_(blue) {}

Color::Color() {
    red_ = 0;
    green_ = 0;
    blue_ = 0;
}

Canals Color::get_canals() const {
    return Canals{red_, green_, blue_};
}

void Color::set_canals(const Canals& canals) {
    red_ = canals.red;
    green_ = canals.green;
    blue_ = canals.blue;
}

FloatColor::FloatColor(float red, float green, float blue) : red(red), green(green), blue(blue) {}

FloatColor::FloatColor(Color color) {
    red = color.get_canals().red;
    green = color.get_canals().green;
    blue = color.get_canals().blue;
}

Color FloatColor::transform_in_color() {
    return Color(std::round(this->red), std::round(this->green), std::round(this->blue));
}

FloatColor FloatColor::operator*(float other) {
    return FloatColor(red * other, green * other, blue * other);
}

FloatColor FloatColor::operator+(FloatColor other) {
    return FloatColor(red + other.red, green + other.green, blue + other.blue);
}