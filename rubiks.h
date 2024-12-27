#ifndef RUBIKS_H
#define RUBIKS_H

#include <stdexcept>
#include "/Users/tejangandhi/Programming/RubiksCube/face.h"

namespace rubiks {

class Cube {
public:
  // Given a list of 6 faces, initializes the cube
  Cube(Face *faces);
  
  // Randomly initialies a given permutation of a cube.
  Cube (bool solved);

  /* 
    Makes a vertical move. Specify which strip to move.
    stripNo defines the position of the strip to move: 0 (left), 1 (middle), 2 (right)
  */
  void verticalMove(int stripNo);

  // Makes a horizontal move. Specify which strip to move.
  // stripNo defines the position of the strip to move: 0 (top), 1 (middle), 2 (bottom)
  void horizontalMove(int stripNo);

private:
  Face up;
  Face down;
  Face front;
  Face back;
  Face left;
  Face right;
};

} // namespace rubiks

#endif