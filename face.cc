#include <initializer_list>
#include <stdexcept>

#include "/Users/tejangandhi/Programming/RubiksCube/face.h"

namespace rubiks {

  // Gets the ith row of the face.
  Color* Face::GetIthRow(int i) {
    return colors_[i];
  }

  // Gets the ith column of the face.
  Color* Face::GetIthColumn(int i) {
    Color colors[] = {colors_[0][i], colors_[1][i], colors_[2][i]};
    return colors;
  }

  bool Face::SwapIthRow(Color row[], int i) {
    if (colors_ == nullptr) {
        return false;
    }
    colors_[i] = row;

    return true;
  }

  bool Face::SwapIthColumn(Color column[], int i) {
    if (colors_ == nullptr) {
        return false;
    }
    for (int ind = 0; ind < 3; ind++) {
        colors_[ind][i] = column[ind];
    }
    return true;
  }

} // namespace rubiks