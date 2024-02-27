#include <stdexcept>

#include "rubiks.h"

namespace rubiks {

/* Represents a single face in rubik's cube. This contains of 9 color tiles */
Face::Face(Color **colors, FacePosition position) : colors_(colors), position_(position) {
  if (colors_ == nullptr) 
      throw std::invalid_argument("colors cannot be null");
  // TODO: Make sure that colors is a valid face.
}
Face::Face() {}


// Given a list of 6 faces, initializes the cube
Cube::Cube(Face *faces) {
  for (int i = 0; i < 6; i++) {
    if (faces->position_ == FacePosition::Up) {
      up = faces[i];
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
Cube::Cube () {
  // Creates a solved cube first. And then unsolves it first.

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