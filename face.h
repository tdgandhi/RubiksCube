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
  Face(Color colors[3][3], FacePosition position) : position_(position) {
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
  Face(Color color, FacePosition position) : position_(position) {
    colors_ = new Color *[3];
    for (int i = 0; i < 3; i++) {
      colors_[i] = new Color[3];
      for (int j = 0; j < 3; j++) {
        colors_[i][j] = color;
      }
    }
  }

  /* Copy Constructor */
  Face(const Face &other) {
    colors_ = new Color *[3];
    position_ = other.position_;
    for (int i = 0; i < 3; i++) {
      colors_[i] = new Color[3];
      for (int j = 0; j < 3; j++) {
        colors_[i][j] = other.colors_[i][j];
      }
    }
  }

  /* This is the default constructor. It gives a cube with random colors.
  Never use this */
  Face() {
    colors_ = new Color *[3];
    for (int i = 0; i < 3; i++) {
      colors_[i] = new Color[3];
      for (int j = 0; j < 3; j++) {
        colors_[i][j] = Color(std::rand() % 6 + 1);
      }
    }
  }

  // Retuns ith row of the face.
  Color *GetIthRow(int i);

  // Returns ith column of the face.
  Color *GetIthColumn(int i);

  // Swaps the ith row of the face with the passed in row.
  bool SwapIthRow(const Color row[], int i);

  // Swaps the ith row of the face with the passed in row.s
  bool SwapIthColumn(const Color column[], int i);

  // Prints the face.
  void PrintFace();

  // Prints the color.
  void PrintColor(Color color);

private:
  // This 2D grid represents the tiles in face.
  Color **colors_;
  // Represents the position of the face in the cube.
  FacePosition position_;
};

} // namespace rubiks