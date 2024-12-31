#include "/Users/tejangandhi/Programming/RubiksCube/cube.h"

#include <iostream>
#include <stdexcept>
#include <string>

namespace rubiks {

namespace {
std::string GetFacePosition(FacePosition p) {
  switch (p) {
  case FacePosition::Up:
    return "Up";
    break;
  case FacePosition::Down:
    return "Down";
    break;
  case FacePosition::Front:
    return "Front";
  case FacePosition::Back:
    return "Back";
  case FacePosition::Left:
    return "Left";
  case FacePosition::Right:
    return "Right";
  default:
    return "error";
    break;
  }
  return "undefined";
}

} // namespace

// Horizontal move.
void Cube::HorizontalMove(int stripNo) {
  Face front = cube[FacePosition::Front];
  // Left -> Front
  cube[FacePosition::Front].SwapIthRow(
      cube[FacePosition::Left].GetIthRow(stripNo), stripNo);
  // Back -> Left
  cube[FacePosition::Left].SwapIthRow(
      cube[FacePosition::Back].GetIthRow(stripNo), stripNo);
  // Right -> Back
  cube[FacePosition::Back].SwapIthRow(
      cube[FacePosition::Right].GetIthRow(stripNo), stripNo);
  // Front -> Right
  cube[FacePosition::Right].SwapIthRow(front.GetIthRow(stripNo), stripNo);
}

// Vertical move.
void Cube::VerticalMove(int stripNo) {
  Face front = cube[FacePosition::Front];
  // Top -> Front
  cube[FacePosition::Front].SwapIthColumn(
      cube[FacePosition::Up].GetIthColumn(stripNo), stripNo);
  // Front -> Down
  cube[FacePosition::Down].SwapIthColumn(
      cube[FacePosition::Front].GetIthColumn(stripNo), stripNo);
  // Down -> Back
  cube[FacePosition::Back].SwapIthColumn(
      cube[FacePosition::Down].GetIthColumn(stripNo), stripNo);
  // Back -> Up
  cube[FacePosition::Up].SwapIthColumn(front.GetIthColumn(stripNo), stripNo);
}

// Randomly rearranges the cube.
void Cube::RearrangeCube() {
  srand(time(NULL));
  int times = rand() % 1000;
  for (int i = 0; i < times; i++) {
    int random_num1 = rand() % 10;
    int random_num2 = rand() % 10;
    int random_num3 = rand() % 3;
    int random_num4 = rand() % 3;

    if (random_num1 < 5)
      HorizontalMove(random_num3);
    if (random_num2 < 5)
      VerticalMove(random_num4);
  }
}

bool Cube::IsValidPermutation() {
  // TODO: Implement this.
  throw std::logic_error("Function not implemented yet");
}

void Cube::PrintCube() {
  for (auto [position, face] : cube) {
    std::cout << GetFacePosition(position) << "\n";
    face.PrintFace();
    std::cout << "\n\n";
  }
}

bool Cube::IsCubeSolved() {
  for (auto [position, face] : cube) {
    if (!face.IsFaceUniform()) return false;
  }
  return true;
}

} // namespace rubiks
