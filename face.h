#ifndef FACE_H
#define FACE_H

#include "types.h"

#include <array>
#include <stdexcept>

namespace rubiks {

// Represents a face of a standard Rubik's Cube.
// Each face is a 3x3 grid of colored tiles.
class Face {
public:
  // Constructor: Creates a face from a 3x3 array of colors.
  Face(const Color colors[3][3], FacePosition position);

  // Constructor: Creates a uniform face with a single color.
  Face(Color color, FacePosition position);

  // Copy constructor
  Face(const Face& other) = default;

  // Move constructor
  Face(Face&& other) noexcept = default;

  // Copy assignment operator
  Face& operator=(const Face& other) = default;

  // Move assignment operator
  Face& operator=(Face&& other) noexcept = default;

  // Destructor
  ~Face() = default;

  // Deleted default constructor - a face must have a position and colors.
  Face() = delete;

  // Returns the ith row of the face (0-indexed).
  // Throws std::out_of_range if i is not in [0, 2].
  std::array<Color, 3> GetIthRow(int i) const;

  // Returns the ith column of the face (0-indexed).
  // Throws std::out_of_range if i is not in [0, 2].
  std::array<Color, 3> GetIthColumn(int i) const;

  // Sets the ith row of the face to the given row.
  // Throws std::out_of_range if i is not in [0, 2].
  void SetIthRow(const std::array<Color, 3>& row, int i);

  // Sets the ith column of the face to the given column.
  // Throws std::out_of_range if i is not in [0, 2].
  void SetIthColumn(const std::array<Color, 3>& column, int i);

  // Returns the color at position (row, col).
  // Throws std::out_of_range if row or col is not in [0, 2].
  Color GetColor(int row, int col) const;

  // Sets the color at position (row, col).
  // Throws std::out_of_range if row or col is not in [0, 2].
  void SetColor(int row, int col, Color color);

  // Returns the position of this face on the cube.
  FacePosition GetPosition() const { return position_; }

  // Prints the face to stdout.
  void PrintFace() const;

  // Prints a single color to stdout.
  static void PrintColor(Color color);

  // Returns true if all tiles on the face have the same color.
  bool IsFaceUniform() const;

  // Rotates the face 90 degrees clockwise.
  void RotateClockwise();

  // Rotates the face 90 degrees counter-clockwise.
  void RotateCounterClockwise();

private:
  // Validates that an index is in the range [0, 2].
  static void ValidateIndex(int index, const char* name);

  // The 3x3 grid of colors representing the tiles on this face.
  std::array<std::array<Color, 3>, 3> colors_;

  // The position of this face on the cube.
  FacePosition position_;
};

} // namespace rubiks

#endif // FACE_H
