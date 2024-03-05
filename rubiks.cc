#include <stdexcept>

#include "rubiks.h"

namespace rubiks {

/* Constructor 1 of Face class, this accept an array of 3x3 and initializes the face */
Face::Face(Color **colors, FacePosition position) : colors_(colors), position_(position) {
  if (colors_ == nullptr)
      throw std::invalid_argument("colors cannot be null");
  // TODO: Make sure that colors is a valid face. Fix it if you want to use it.
}

/* Constructor 2 of Face class. This accepts a color and initializes entire face with that color */
Face::Face(Color color, FacePosition position) : position_(position) {

}

/* This is the default constructor, never use this */
Face::Face() {

}



// Given a list of 6 faces, initializes the cube
Cube::Cube(Face *faces) {
  for (int i = 0; i < 6; i++) {
    if (faces->position_ == FacePosition::Up) {
      up = Face(faces[i]);
    }
    if (faces-> position_ == FacePosition::Front) {
      front = faces[i];
    }
    if (faces-> position_ == FacePosition::Down) {
      down = faces[i];
    }
    if (faces-> position_ == FacePosition::Back) {
      back = faces[i];
    }
    if (faces -> position_ == FacePosition::Left) {
      left = faces[i];
    }
    if (faces -> position_ == FacePosition::Right) {
      right = faces[i];
    }
  }
}
// Randomly initialies a given permutation of a cube.
Cube::Cube (bool solved = false) {
  // Creates a solved cube first. And then unsolves it first.
  // Solved cube.
  up.position_ = FacePosition::Up;
  down.position_ = FacePosition::Down;
  front.position_ = FacePosition::Front;
  back.position_ = FacePosition::Back;
  left.position_ = FacePosition::Left;
  right.position_ = FacePosition::Right;
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      up.colors_[i][j] = Color::Color1;
      down.colors_[i][j] = Color::Color2;
      front.colors_[i][j] = Color::Color3;
      back.colors_[i][j] = Color::Color4;
      left.colors_[i][j] = Color::Color5;
      right.colors_[i][j] = Color::Color6;
    }
  }

  // Now unsolve it.
  srand(time(0));
  for (int i = 0; i < rand() % 100; i++) {
    srand(time(0));
    verticalMove(rand() % 3);
    srand(time(0));
    horizontalMove(rand() % 3);
  }
}

/* 
  Makes a vertical move. Specify which strip to move.
  stripNo defines the position of the strip to move: 0 (left), 1 (middle), 2 (right)
*/
void Cube::verticalMove(int stripNo) {
  // Store top somewhere.
  Color top_temp[3];
  top_temp[0] = up.colors_[0][stripNo];
  top_temp[1] = up.colors_[1][stripNo];
  top_temp[2] = up.colors_[2][stripNo];

  // back goes to top
  up.colors_[0][stripNo] = back.colors_[0][stripNo];
  up.colors_[1][stripNo] = back.colors_[0][stripNo];
  up.colors_[2][stripNo] = back.colors_[0][stripNo];

  // botom goes to back
  back.colors_[0][stripNo] = down.colors_[0][stripNo];
  back.colors_[1][stripNo] = down.colors_[1][stripNo];
  back.colors_[2][stripNo] = down.colors_[2][stripNo];

  // Front goes to bottom
  down.colors_[0][stripNo] = front.colors_[0][stripNo];
  down.colors_[1][stripNo] = front.colors_[1][stripNo];
  down.colors_[2][stripNo] = front.colors_[2][stripNo];

  // Stored value goes to front
  front.colors_[0][0] = top_temp[0];
  front.colors_[0][1] = top_temp[1];
  front.colors_[0][2] = top_temp[2];
}

// Makes a horizontal move. Specify which strip to move.
// stripNo defines the position of the strip to move: 0 (top), 1 (middle), 2 (bottom)
void Cube::horizontalMove(int stripNo) {
  // front, right, back, left
  
  // store front
  Color front_temp[3];
  front_temp[0] = front.colors_[stripNo][0];
  front_temp[1] = front.colors_[stripNo][1];
  front_temp[2] = front.colors_[stripNo][2];

  // left goes to front
  front.colors_[stripNo][0] = left.colors_[stripNo][0];
  front.colors_[stripNo][1] = left.colors_[stripNo][1];
  front.colors_[stripNo][2] = left.colors_[stripNo][2];

  // back goes to left 
  left.colors_[stripNo][0] = back.colors_[stripNo][0];
  left.colors_[stripNo][1] = back.colors_[stripNo][1];
  left.colors_[stripNo][2] = back.colors_[stripNo][2];
  
  // right goes to back
  back.colors_[stripNo][0] = right.colors_[stripNo][0];
  back.colors_[stripNo][1] = right.colors_[stripNo][1];
  back.colors_[stripNo][2] = right.colors_[stripNo][2];

  // stored value (front) goes to right
  right.colors_[stripNo][0] = front_temp[0];
  right.colors_[stripNo][1] = front_temp[1];
  right.colors_[stripNo][2] = front_temp[2];
}

} // namespace rubiks