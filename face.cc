#include <initializer_list>
#include <iostream>
#include <stdexcept>

#include "/Users/tejangandhi/Programming/RubiksCube/face.h"

namespace rubiks {

// Gets the ith row of the face.
Color *Face::GetIthRow(int i) {
  Color *colors = new Color[3];
  for (int ind = 0; ind < 3; ind++) {
    colors[ind] = colors_[i][ind];
  }
  // *colors = {colors_[i][0], colors_[i][1], colors_[i][2]};
  return colors;
}

// Gets the ith column of the face.
Color *Face::GetIthColumn(int i) {
  Color *colors = new Color[3];
  for (int ind = 0; ind < 3; ind++) {
    colors[ind] = colors_[ind][i];
  }
  return colors;
}

bool Face::SwapIthRow(const Color row[], int i) {
  if (colors_ == nullptr) {
    return false;
  }
  for (int ind = 0; ind < 3; ind++) {
    colors_[i][ind] = row[ind];
  }
  return true;
}

bool Face::SwapIthColumn(const Color column[], int i) {
  if (colors_ == nullptr) {
    return false;
  }
  for (int ind = 0; ind < 3; ind++) {
    colors_[ind][i] = column[ind];
  }
  return true;
}

void Face::PrintFace() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      PrintColor(colors_[i][j]);
      std::cout << " ";
    }
    std::cout << "\n";
  }
}

void Face::PrintColor(Color color) {
  switch (color) {
  case Color::Color1:
    std::cout << "Color1";
    break;
  case Color::Color2:
    std::cout << "Color2";
    break;
  case Color::Color3:
    std::cout << "Color3";
    break;
  case Color::Color4:
    std::cout << "Color4";
    break;
  case Color::Color5:
    std::cout << "Color5";
    break;
  case Color::Color6:
    std::cout << "Color6";
    break;
  default:
    std::cout << "Error";
    break;
  }
}

bool Face::IsFaceUniform() {
    Color first_color = colors_[0][0];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (colors_[i][j] != first_color) return false;
      }
    }
  return true;
}

} // namespace rubiks