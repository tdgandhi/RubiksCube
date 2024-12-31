#include "cube.cc"

#include "/Users/tejangandhi/Programming/CatchTesting/catch_amalgamated.hpp"

namespace rubiks {

// Test printing.
TEST_CASE ("TestPrinting", "[Console log]") {
    Cube cube; // Default constructor. Randomly initializes the face.
    std::cout << "\n";
    cube.PrintCube();
}

}  // namespace rubiks