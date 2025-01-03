#ifndef CUBE_H
#define CUBE_H

#include <map>
#include <stdexcept>
#include <iostream>

#include "/Users/tejangandhi/Programming/RubiksCube/face.h"

namespace rubiks {

class Cube {
public:
  // Given another cube, initializes this cube.
  Cube(const Cube &other) {
    for (auto [position, face] : other.cube) {
      cube[position] = Face(face);
    }
  }

  // Randomly initialies a given permutation of a cube.
  Cube(bool solved) {
    for (int i = 1; i <= 6; i++) {
      cube[FacePosition(i)] = Face(Color(i), FacePosition(i));
    }
    // They don't want it solved.
    if (!solved) {
      // Randomly unsolve it.
      RearrangeCube();
    }
  }

  // Default constructor. Returns an unsolved cube.
  Cube() : Cube(false) {}

  /*
    Makes a vertical move. Specify which strip to move.
    stripNo defines the position of the strip to move: 0 (left), 1 (middle), 2
    (right)
  */
  void VerticalMove(int stripNo);

  // Makes a horizontal move. Specify which strip to move.
  // stripNo defines the position of the strip to move: 0 (top), 1 (middle), 2
  // (bottom).
  void HorizontalMove(int stripNo);

  // Randomly rearranges the cube using random number of vertical/horizontal
  // moves.
  void RearrangeCube();

  // Check if the given cube is a valid permutation or not.
  bool IsValidPermutation();

  // Prints the cube.
  void PrintCube();

  // Check if the cube is solved or not.
  bool IsCubeSolved();

private:
  // A map which stores face positions with the faces.
  std::map<FacePosition, Face> cube;
};

} // namespace rubiks

#endif