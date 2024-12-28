#include <vector>

namespace rubiks {

enum class Color {
  Color1 = 1,
  Color2 = 2,
  Color3 = 3,
  Color4 = 4,
  Color5 = 5,
  Color6 = 6
};
enum class FacePosition {
  Up = 1,
  Down = 2,
  Front = 3,
  Back = 4,
  Left = 5,
  Right = 6
};

// Represents a face of a standard rubik's cube.
class Face {
public:
  /* Constructor 1 of Face class, this accept an array of 3x3 and initializes
   * the face */
  Face::Face(Color colors[3][3], FacePosition position) : position_(position) {
    colors_ = new Color *[3];
    for (int i = 0; i < 3; i++) {
      colors_[i] = new Color[3];
      for (int j = 0; j < 3; j++) {
        colors_[i][j] = colors[i][j];
      }
    }
  }

  /* Constructor 2 of Face class. This accepts a color and initializes entire
   * face with that color */
  Face::Face(Color color, FacePosition position) : position_(position) {
    colors_ = new Color *[3];
    for (int i = 0; i < 3; i++) {
      colors_[i] = new Color[3];
      for (int j = 0; j < 3; j++) {
        colors_[i][j] = color;
      }
    }
  }

  /* This is the default constructor. It gives a cube with random colors.
  Never use this */
  Face::Face() {
    colors_ = new Color *[3];
    for (int i = 0; i < 3; i++) {
      colors_[i] = new Color[3];
      for (int j = 0; j < 3; j++) {
        colors_[i][j] = Color(std::rand() % 6 + 1);
      }
    }
  }

  Color *GetIthRow(int i);

  Color *GetIthColumn(int i);

  bool SwapIthRow(Color color[], int i);

  bool SwapIthColumn(Color color[], int i);

private:
  // This 2D grid represents the tiles in face.
  Color **colors_;
  // Represents the position of the face in the cube.
  FacePosition position_;
};

} // namespace rubiks