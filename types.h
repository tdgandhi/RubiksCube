#ifndef TYPES_H
#define TYPES_H

namespace rubiks {

// Represents the six colors on a standard Rubik's Cube.
// You can rename these to actual color names (White, Yellow, etc.) if preferred.
enum class Color {
  Color1 = 1,
  Color2 = 2,
  Color3 = 3,
  Color4 = 4,
  Color5 = 5,
  Color6 = 6
};

// Represents the six face positions on a standard Rubik's Cube.
enum class FacePosition {
  Up = 1,
  Down = 2,
  Front = 3,
  Back = 4,
  Left = 5,
  Right = 6
};

} // namespace rubiks

#endif // TYPES_H