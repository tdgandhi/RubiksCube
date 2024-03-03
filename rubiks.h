#ifndef RUBIKS_H
#define RUBIKS_H

#include <stdexcept>

namespace rubiks {


enum class Color { Color1, Color2, Color3, Color4, Color5, Color6 };
enum class FacePosition { Up, Down, Front, Back, Left, Right };

class Face {
 public:
  /* Constructor 1 of Face class, this accept an array of 3x3 and initializes the face */
  Face(Color **colors, FacePosition position);
  /* Constructor 2 of Face class, this accept a single color and initializes all the tiles with the same color */
  Face(Color color, FacePosition position);
  
  /* This is the default constructor. Never use this */
  Face() {};
  Color **colors_; // This 2D grid represents the tiles in face.
  FacePosition position_;
};

class Cube {
public:
  // Given a list of 6 faces, initializes the cube
  Cube(Face *faces);
  
  // Randomly initialies a given permutation of a cube.
  Cube ();

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