#include <stdexcept>

enum class Color { Color1, Color2, Color3, Color4, Color5, Color6 };
enum class FacePosition { Up, Down, Front, Back, Left, Right };

/* Represents a single face in rubik's cube. This contains of 9 color tiles */
class Face {
public:
  Face(Color **colors, FacePosition position) : colors_(colors), position_(position) {
    if (colors_ == nullptr) 
        throw std::invalid_argument("colors cannot be null");
    // TODO: Make sure that colors is a valid face.
  }
  Face() {}

  Color **colors_; // This 2D grid represents the tiles in face.
  FacePosition position_;
};

class Cube {
public:
  // Cube(Face *faces) : faces_(faces) {}
  Cube () {}

  /* 
    Makes a vertical move. Specify which strip to move.
    stripNo defines the position of the strip to move: 0 (left), 1 (middle), 2 (right)
  */
  void verticalMove(int stripNo) {
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
  void horizontalMove(int stripNo) {
    // front, right, back, left
    
    // store left
    Color top_temp[3];
    
  }



private:
  Face up;
  Face down;
  Face front;
  Face back;
  Face left;
  Face right;
};

