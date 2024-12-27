#include <vector>

namespace rubiks {

enum class Color { Color1, Color2, Color3, Color4, Color5, Color6 };
enum class FacePosition { Up, Down, Front, Back, Left, Right };

// Represents a face of a standard rubik's cube.
class Face {
 public:
  /* Constructor 1 of Face class, this accept an array of 3x3 and initializes the face */
  Face(std::vector<std::vector<Color>> colors, FacePosition position);

  /* Constructor 2 of Face class, this accept a single color and initializes all the tiles with the same color */
  Face(Color color, FacePosition position);
  
  /* This is the default constructor. Never use this */
  Face() {};

  std::vector<std::vector<Color>> colors_; // This 2D grid represents the tiles in face.
  FacePosition position_;
};

}  // namespace rubiks 