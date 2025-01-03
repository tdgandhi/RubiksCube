#include "cube.h"

#include <iostream>

#include "/Users/tejangandhi/Programming/CatchTesting/catch_amalgamated.hpp"

namespace rubiks {

// Test printing.
TEST_CASE ("TestPrinting", "[Console log]") {
    Cube cube; // Returns the solved cube.
    std::cout << "Printing the cube: \n";
    // cube.RearrangeCube();
    cube.PrintCube();
}

}  // namespace rubiks