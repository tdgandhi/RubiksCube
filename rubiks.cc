#include "rubiks.h"

#include <iostream>

#include "cube.h"

int main() {
  rubiks::Cube cube(false);

  std::cout << "=== Scrambled cube ===\n";
  cube.PrintCube();
  std::cout << "Solved? " << (cube.IsCubeSolved() ? "yes" : "no") << "\n\n";

  cube.SolveCube();

  std::cout << "=== After solving ===\n";
  cube.PrintCube();
  std::cout << "Solved? " << (cube.IsCubeSolved() ? "yes" : "no") << "\n";

  return 0;
}