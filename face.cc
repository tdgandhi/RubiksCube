#include <stdexcept>
#include <initializer_list>

#include "/Users/tejangandhi/Programming/RubiksCube/face.h"

namespace rubiks {

    /* Constructor 1 of Face class, this accept an array of 3x3 and initializes the face */
    Face::Face(std::vector<std::vector<Color>> face, FacePosition position) : colors_(face), position_(position) {}

    /* Constructor 2 of Face class. This accepts a color and initializes entire face with that color */
    Face::Face(Color color, FacePosition position) : position_(position)
    {  
        // Color color_grid[3][3] = ;
        colors_ = {{color, color, color}, {color, color, color}, {color, color, color}};
    }

    /* This is the default constructor, never use this */
    Face::Face()
    {
        colors_ = {{Color::Color1, Color::Color1, Color::Color1}, {Color::Color1, Color::Color1, Color::Color1}, {Color::Color1, Color::Color1, Color::Color1}};
    }

} // namespace rubiks