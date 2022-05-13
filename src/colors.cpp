#include "../include/colors.hpp"

Color::Color():r(0.5), g(0.3), b(0.8){}; //couleur par défaut est violet

Color::Color(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}