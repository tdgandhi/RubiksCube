#ifndef CUBE_H
#define CUBE_H

#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>

#include "/Users/tejangandhi/Programming/RubiksCube/face.h"

namespace rubiks {

class Cube {
public:
  // Given another cube, initializes this cube.
  Cube(const Cube &other) {
    for (auto [position, face] : other.cube) {
      cube.emplace(position, face);
    }
  }

  // Randomly initializes a given permutation of a cube.
  Cube(bool solved) {
    for (int i = 1; i <= 6; i++) {
      cube.emplace(FacePosition(i), Face(Color(i), FacePosition(i)));
    }
    if (!solved) {
      RearrangeCube();
    }
  }

  // Default constructor. Returns an unsolved cube.
  Cube() : Cube(false) {}

  // Makes a vertical move. stripNo: 0 (left), 1 (middle), 2 (right).
  void VerticalMove(int stripNo);

  // Makes a horizontal move. stripNo: 0 (top), 1 (middle), 2 (bottom).
  void HorizontalMove(int stripNo);

  // Randomly scrambles the cube and records all moves made.
  void RearrangeCube();

  // Solves the cube by reversing every recorded move in reverse order.
  // Each move's inverse is the same move applied 3 more times.
  void SolveCube();

  // Check if the given cube is a valid permutation or not.
  bool IsValidPermutation();

  // Prints the cube.
  void PrintCube();

  // Check if the cube is solved or not.
  bool IsCubeSolved();

private:
  // Represents a single move applied to the cube.
  struct Move {
    bool is_horizontal;
    int strip;
  };

  // A map which stores face positions with the faces.
  std::map<FacePosition, Face> cube;

  // History of every move applied since the last solve.
  std::vector<Move> move_history_;

  // Internal versions that skip recording (used during solving).
  void ApplyHorizontalMove(int stripNo);
  void ApplyVerticalMove(int stripNo);
};

} // namespace rubiks

#endif