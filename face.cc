#include "face.h"

#include <iostream>
#include <stdexcept>

namespace rubiks {

// Constructor: Creates a face from a 3x3 array of colors.
Face::Face(const Color colors[3][3], FacePosition position) 
    : position_(position) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      colors_[i][j] = colors[i][j];
    }
  }
}

// Constructor: Creates a uniform face with a single color.
Face::Face(Color color, FacePosition position) 
    : position_(position) {
  for (auto& row : colors_) {
    row.fill(color);
  }
}

// Returns the ith row of the face (0-indexed).
std::array<Color, 3> Face::GetIthRow(int i) const {
  ValidateIndex(i, "row");
  return colors_[i];
}

// Returns the ith column of the face (0-indexed).
std::array<Color, 3> Face::GetIthColumn(int i) const {
  ValidateIndex(i, "column");
  return {colors_[0][i], colors_[1][i], colors_[2][i]};
}

// Sets the ith row of the face to the given row.
void Face::SetIthRow(const std::array<Color, 3>& row, int i) {
  ValidateIndex(i, "row");
  colors_[i] = row;
}

// Sets the ith column of the face to the given column.
void Face::SetIthColumn(const std::array<Color, 3>& column, int i) {
  ValidateIndex(i, "column");
  for (int row = 0; row < 3; row++) {
    colors_[row][i] = column[row];
  }
}

// Returns the color at position (row, col).
Color Face::GetColor(int row, int col) const {
  ValidateIndex(row, "row");
  ValidateIndex(col, "column");
  return colors_[row][col];
}

// Sets the color at position (row, col).
void Face::SetColor(int row, int col, Color color) {
  ValidateIndex(row, "row");
  ValidateIndex(col, "column");
  colors_[row][col] = color;
}

// Prints the face to stdout.
void Face::PrintFace() const {
  for (const auto& row : colors_) {
    for (Color color : row) {
      PrintColor(color);
      std::cout << " ";
    }
    std::cout << "\n";
  }
}

// Prints a single color to stdout.
void Face::PrintColor(Color color) {
  static const char* kColorNames[] = {
    "Invalid",  // Index 0 (not used)
    "Color1",   // Index 1
    "Color2",   // Index 2
    "Color3",   // Index 3
    "Color4",   // Index 4
    "Color5",   // Index 5
    "Color6"    // Index 6
  };

  int index = static_cast<int>(color);
  if (index >= 1 && index <= 6) {
    std::cout << kColorNames[index];
  } else {
    std::cout << "Error";
  }
}

// Returns true if all tiles on the face have the same color.
bool Face::IsFaceUniform() const {
  Color first_color = colors_[0][0];
  for (const auto& row : colors_) {
    for (Color color : row) {
      if (color != first_color) {
        return false;
      }
    }
  }
  return true;
}

// Rotates the face 90 degrees clockwise.
void Face::RotateClockwise() {
  std::array<std::array<Color, 3>, 3> rotated;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      rotated[j][2 - i] = colors_[i][j];
    }
  }
  colors_ = rotated;
}

// Rotates the face 90 degrees counter-clockwise.
void Face::RotateCounterClockwise() {
  std::array<std::array<Color, 3>, 3> rotated;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      rotated[2 - j][i] = colors_[i][j];
    }
  }
  colors_ = rotated;
}

// Validates that an index is in the range [0, 2].
void Face::ValidateIndex(int index, const char* name) {
  if (index < 0 || index >= 3) {
    throw std::out_of_range(
        std::string("Face ") + name + " index " + 
        std::to_string(index) + " is out of range [0, 2]");
  }
}

} // namespace rubiks
