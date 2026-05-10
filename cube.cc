#include "/Users/tejangandhi/Programming/RubiksCube/cube.h"

#include <iostream>
#include <stdexcept>
#include <string>

namespace rubiks {

namespace {
std::string GetFacePositionStr(FacePosition p) {
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

// Internal horizontal move — does not record to history.
// Read all values first, then write, to avoid reading a face after it's been modified.
void Cube::ApplyHorizontalMove(int stripNo) {
  auto front_row = cube.at(FacePosition::Front).GetIthRow(stripNo);
  auto left_row  = cube.at(FacePosition::Left).GetIthRow(stripNo);
  auto back_row  = cube.at(FacePosition::Back).GetIthRow(stripNo);
  auto right_row = cube.at(FacePosition::Right).GetIthRow(stripNo);

  // Cycle: Left -> Front -> Right -> Back -> Left
  cube.at(FacePosition::Front).SetIthRow(left_row,  stripNo);
  cube.at(FacePosition::Left).SetIthRow(back_row,   stripNo);
  cube.at(FacePosition::Back).SetIthRow(right_row,  stripNo);
  cube.at(FacePosition::Right).SetIthRow(front_row, stripNo);
}

// Internal vertical move — does not record to history.
// Read all values first, then write, to avoid reading a face after it's been modified.
void Cube::ApplyVerticalMove(int stripNo) {
  auto up_col    = cube.at(FacePosition::Up).GetIthColumn(stripNo);
  auto front_col = cube.at(FacePosition::Front).GetIthColumn(stripNo);
  auto down_col  = cube.at(FacePosition::Down).GetIthColumn(stripNo);
  auto back_col  = cube.at(FacePosition::Back).GetIthColumn(stripNo);

  // Cycle: Up -> Front -> Down -> Back -> Up
  cube.at(FacePosition::Front).SetIthColumn(up_col,    stripNo);
  cube.at(FacePosition::Down).SetIthColumn(front_col,  stripNo);
  cube.at(FacePosition::Back).SetIthColumn(down_col,   stripNo);
  cube.at(FacePosition::Up).SetIthColumn(back_col,     stripNo);
}

// Public horizontal move — applies the move and records it.
void Cube::HorizontalMove(int stripNo) {
  ApplyHorizontalMove(stripNo);
  move_history_.push_back({true, stripNo});
}

// Public vertical move — applies the move and records it.
void Cube::VerticalMove(int stripNo) {
  ApplyVerticalMove(stripNo);
  move_history_.push_back({false, stripNo});
}

// Randomly scrambles the cube. All moves are recorded in move_history_.
void Cube::RearrangeCube() {
  srand(time(NULL));
  int times = rand() % 20 + 10; // 10–29 scramble moves
  for (int i = 0; i < times; i++) {
    int strip = rand() % 3;
    if (rand() % 2 == 0)
      HorizontalMove(strip);
    else
      VerticalMove(strip);
  }
}

// Solves the cube by undoing every recorded move in reverse order.
// The inverse of any single move is that same move applied 3 more times
// (since 4 applications = identity in a cyclic group of order 4).
SolveCubeStats Cube::SolveCube() {
  SolveCubeStats stats;
  stats.undo_iterations = move_history_.size();
  for (int i = static_cast<int>(move_history_.size()) - 1; i >= 0; i--) {
    const Move& m = move_history_[i];
    for (int j = 0; j < 3; j++) {
      if (m.is_horizontal)
        ApplyHorizontalMove(m.strip);
      else
        ApplyVerticalMove(m.strip);
      stats.primitive_moves++;
    }
  }
  move_history_.clear();
  return stats;
}

bool Cube::IsValidPermutation() {
  // TODO: Implement this.
  throw std::logic_error("Function not implemented yet");
}

void Cube::PrintCube() {
  for (auto [position, face] : cube) {
    std::cout << GetFacePositionStr(position) << "\n";
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
