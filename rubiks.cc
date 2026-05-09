#include "rubiks.h"

#include <chrono>
#include <iomanip>
#include <iostream>

#include "cube.h"

int main() {
  rubiks::Cube cube(false);

  std::cout << "=== Scrambled cube ===\n";
  cube.PrintCube();
  std::cout << "Solved? " << (cube.IsCubeSolved() ? "yes" : "no") << "\n\n";

  const auto solve_start = std::chrono::steady_clock::now();
  cube.SolveCube();
  const auto solve_end = std::chrono::steady_clock::now();
  const double solve_seconds =
      std::chrono::duration<double>(solve_end - solve_start).count();
  std::cout << std::fixed << std::setprecision(6) << "Solve time: " << solve_seconds
            << " s\n\n";

  std::cout << "=== After solving ===\n";
  cube.PrintCube();
  std::cout << "Solved? " << (cube.IsCubeSolved() ? "yes" : "no") << "\n";

  return 0;
}