#include "rubiks.h"

#include <iostream>

#include "cube.h"

int main() {
  rubiks::Cube cube(false);
  std::cout << "Print if the cube is solved or not: " << ((cube.IsCubeSolved() ==
          true) ? "true" : "false");
  int i = 0;
  while (!cube.IsCubeSolved()) {
    i++;
    if (i % 1000 == 0) std::cout << "Iterations: " << i << "\n";
    cube.RearrangeCube();
  }
  return 0;
}