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
  const rubiks::SolveCubeStats stats = cube.SolveCube();
  const auto solve_end = std::chrono::steady_clock::now();
  const double solve_seconds =
      std::chrono::duration<double>(solve_end - solve_start).count();
  std::cout << std::fixed << std::setprecision(6) << "Solve time: " << solve_seconds
            << " s\n";
  std::cout << "Undo iterations (recorded scramble moves reversed): "
            << stats.undo_iterations << "\n";
  std::cout << "Primitive moves (strip operations during solve): " << stats.primitive_moves
            << "\n\n";

  std::cout << "=== After solving ===\n";
  cube.PrintCube();
  std::cout << "Solved? " << (cube.IsCubeSolved() ? "yes" : "no") << "\n";

  return 0;
}