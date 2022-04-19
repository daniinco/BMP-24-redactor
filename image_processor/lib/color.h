#pragma once

struct Canals {
    int red;
    int green;
    int blue;
};

class Color {
public:
    Color(); // idk why but resize in crop doesnt work without it(may be it transform all not needed elems in Color())
    Color(int red, int green, int blue);
    Canals get_canals() const;
    void set_canals(const Canals&);

private:
    int red_;
    int green_;
    int blue_;
};

class FloatColor {
public:
    FloatColor(float red, float green, float blue);
    FloatColor(Color color);
    Color transform_in_color();
    FloatColor operator*(float other);
    FloatColor operator+(FloatColor other);
    float red;
    float green;
    float blue;
};