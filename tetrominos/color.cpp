#include "color.h"
Color::Color() {}

Color::Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b){}

uint8_t Color::getRed() {
  return r;
}

uint8_t Color::getGreen() {
  return g;
}

uint8_t Color::getBlue() {
  return b;
}

const Color Color::Cyan(0, 255, 255);
const Color Color::Blue(0, 0, 255);
const Color Color::Orange(255, 165, 0);
const Color Color::Yellow(255, 255, 0);
const Color Color::Green(0, 255, 0);
const Color Color::Purple(128, 0, 128);
const Color Color::Red(255, 0, 0);
const Color Color::Black(0, 0, 0);
const Color Color::White(255, 255, 255);

bool Color::operator==(Color color) {
  return this->r == color.r && this->g == color.g && this->b == color.b;
}
