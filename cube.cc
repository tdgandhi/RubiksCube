#include "/Users/tejangandhi/Programming/RubiksCube/cube.h"

namespace rubiks {

void Cube::HorizontalMove(int stripNo) {
  Face front = cube[FacePosition::Front];
  // Left -> Front
  front.SwapIthRow(cube[FacePosition::Left].GetIthRow(stripNo), stripNo);
  // Back -> Left
  cube[FacePosition::Left].SwapIthRow(
      cube[FacePosition::Back].GetIthRow(stripNo), stripNo);
  // Right -> Back
  cube[FacePosition::Back].SwapIthRow(
      cube[FacePosition::Right].GetIthRow(stripNo), stripNo);
  // Front -> Right
  cube[FacePosition::Right].SwapIthRow(front.GetIthRow(stripNo), stripNo);
}

void Cube::VerticalMove(int stripNo) {
    Face front = cube[FacePosition::Front];
    // Top -> Front
    cube[FacePosition::Front].SwapIthColumn(cube[FacePosition::Up].GetIthColumn(stripNo), stripNo);
    // Front -> Down
    cube[FacePosition::Down].SwapIthColumn(cube[FacePosition::Front].GetIthColumn(stripNo), stripNo);
    // Down -> Back 
    cube[FacePosition::Back].SwapIthColumn(cube[FacePosition::Down].GetIthColumn(stripNo), stripNo);
    // Back -> Up
    cube[FacePosition::Up].SwapIthColumn(front.GetIthColumn(stripNo), stripNo);
}

void Cube::RearrangeCube() {

  HorizontalMove(0);
  VerticalMove(1);
}

} // namespace rubiks
