#include <stdexcept>

enum class Color { Color1, Color2, Color3, Color4, Color5, Color6 };
enum class FacePosition { Up, Down, Front, Back, Left, Right };

class Face {
public:
  Face(Color **colors, FacePosition position) : colors_(colors), position_(position) {
    if (colors_ == nullptr) 
        throw std::invalid_argument("colors cannot be null");
    // TODO: Make sure that colors is a valid face.
  }
  Face() {}

  Color **colors_; // This 2D grid represents the 
  FacePosition position_;
};

class Cube {
public:
  // Cube(Face *faces) : faces_(faces) {}
  Cube () {}

  // Makes a vertical move. Specify which strip to move: 0 (left), 1 (middle), 2 (right)
  void verticalMove(int stripNo) {
    // Affects top, front, bottom, back
    // Front goes to bottom, botom goes to back, stored value goes to 
    // front.
    // Store top somewhere.
    Color top_temp[3];
    top_temp[0] = up.colors_[0][0];
    top_temp[1] = up.colors_[1][0];
    top_temp[2] = up.colors_[2][0];

    // back goes to top
    up.colors_[0][0] = back.colors_[0][0];
    up.colors_[0][1] = back.colors_[0][1];
    up.colors_[0][2] = back.colors_[0][2];



  }

private:
  Face up;
  Face down;
  Face front;
  Face back;
  Face left;
  Face right;
};

