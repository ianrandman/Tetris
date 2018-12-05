#ifndef TETRIS_COLOR_H
#define TETRIS_COLOR_H

#include <stdint.h>

class Color {
 public:
  Color();
  Color(uint8_t r, uint8_t g, uint8_t b);

  uint8_t getRed();
  uint8_t getGreen();
  uint8_t getBlue();

  static const Color Cyan;
  static const Color Blue;
  static const Color Orange;
  static const Color Yellow;
  static const Color Green;
  static const Color Purple;
  static const Color Red;
  static const Color Black;
  static const Color White;

  bool operator==(Color otherColor);

 private:
  uint8_t r, g, b;
};

#endif