#include "/Users/tejangandhi/Programming/RubiksCube/face.h"

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iostream>

#include "/Users/tejangandhi/Programming/CatchTesting/catch_amalgamated.hpp"

namespace rubiks {

// // Test printing.
// TEST_CASE ("TestPrinting", "[Console log]") {
//     Face face; // Default constructor. Randomly initializes the face.
//     std::cout << "\n";
//     face.PrintFace();
// }

// Initialize a face, check for all rows and columns using Getters.
TEST_CASE("TestFaceInitialization", "[GetRows, GetColumns]") {
  Color face_color[3][3];
  srand(time(0));
  // Randomly initialize a face.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      face_color[i][j] = Color(rand() % 6);
    }
  }

  Face face(face_color, FacePosition::Up);

  // Check for first row
  int row = 0;
  Color *first_row{face.GetIthRow(row)};
  REQUIRE(face_color[row][0] == first_row[0]);
  REQUIRE(face_color[row][1] == first_row[1]);
  REQUIRE(face_color[row][2] == first_row[2]);

  // Check for second row
  row++;
  Color *second_row{face.GetIthRow(row)};
  REQUIRE(face_color[row][0] == second_row[0]);
  REQUIRE(face_color[row][1] == second_row[1]);
  REQUIRE(face_color[row][2] == second_row[2]);

  // Check for third row
  row++;
  Color *third_row{face.GetIthRow(row)};
  REQUIRE(face_color[row][0] == third_row[0]);
  REQUIRE(face_color[row][1] == third_row[1]);
  REQUIRE(face_color[row][2] == third_row[2]);

  delete first_row;
  delete second_row;
  delete third_row;

  // Check for first column
  int column = 0;
  Color *first_column{face.GetIthColumn(column)};
  REQUIRE(face_color[0][column] == first_column[0]);
  REQUIRE(face_color[1][column] == first_column[1]);
  REQUIRE(face_color[2][column] == first_column[2]);

  // Check for second column
  column++;
  Color *second_column{face.GetIthColumn(column)};
  REQUIRE(face_color[0][column] == second_column[0]);
  REQUIRE(face_color[1][column] == second_column[1]);
  REQUIRE(face_color[2][column] == second_column[2]);

  // Check for third row
  column++;
  Color *third_column{face.GetIthColumn(column)};
  REQUIRE(face_color[0][column] == third_column[0]);
  REQUIRE(face_color[1][column] == third_column[1]);
  REQUIRE(face_color[2][column] == third_column[2]);

  delete first_column;
  delete second_column;
  delete third_column;
}

// Initialize a given color, check for all rows and columns using Getters.
TEST_CASE("TestColorInitialization", "[GetRows, GetColumns]") {
  Color face_color[3][3];
  srand(time(0));
  // Initialize a face with all the same colors.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      face_color[i][j] = Color::Color1;
    }
  }

  Face face(face_color, FacePosition::Up);

  // Check for first row
  int row = 0;
  Color *first_row{face.GetIthRow(row)};
  REQUIRE(face_color[row][0] == first_row[0]);
  REQUIRE(face_color[row][1] == first_row[1]);
  REQUIRE(face_color[row][2] == first_row[2]);

  // Check for second row
  row++;
  Color *second_row{face.GetIthRow(row)};
  REQUIRE(face_color[row][0] == second_row[0]);
  REQUIRE(face_color[row][1] == second_row[1]);
  REQUIRE(face_color[row][2] == second_row[2]);

  // Check for third row
  row++;
  Color *third_row{face.GetIthRow(row)};
  REQUIRE(face_color[row][0] == third_row[0]);
  REQUIRE(face_color[row][1] == third_row[1]);
  REQUIRE(face_color[row][2] == third_row[2]);

  delete first_row;
  delete second_row;
  delete third_row;

  // Check for first column
  int column = 0;
  Color *first_column{face.GetIthColumn(column)};
  REQUIRE(face_color[0][column] == first_column[0]);
  REQUIRE(face_color[1][column] == first_column[1]);
  REQUIRE(face_color[2][column] == first_column[2]);

  // Check for second column
  column++;
  Color *second_column{face.GetIthColumn(column)};
  REQUIRE(face_color[0][column] == second_column[0]);
  REQUIRE(face_color[1][column] == second_column[1]);
  REQUIRE(face_color[2][column] == second_column[2]);

  // Check for third row
  column++;
  Color *third_column{face.GetIthColumn(column)};
  REQUIRE(face_color[0][column] == third_column[0]);
  REQUIRE(face_color[1][column] == third_column[1]);
  REQUIRE(face_color[2][column] == third_column[2]);

  delete first_column;
  delete second_column;
  delete third_column;
}

// Initialize and swap first row, and then check all the rows and columns.
TEST_CASE("TestSwapRows", "[SwapRows, GetRows, GetColumns]") {
  Color face_color[3][3];
  srand(time(0));
  // Initialize a face with all the same colors.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      face_color[i][j] = Color::Color1;
    }
  }

  Face face(face_color, FacePosition::Up);

  // Swap first row with another row.
  Color swapped_row[] = {Color::Color1, Color::Color2, Color::Color3};
  
  face.SwapIthRow(swapped_row, 0);

  // Check for first row
  int row = 0;
  Color *first_row{face.GetIthRow(row)};
  REQUIRE(swapped_row[0] == first_row[0]);
  REQUIRE(swapped_row[1] == first_row[1]);
  REQUIRE(swapped_row[2] == first_row[2]);

  // Check for second row
  row++;
  Color *second_row{face.GetIthRow(row)};
  REQUIRE(face_color[row][0] == second_row[0]);
  REQUIRE(face_color[row][1] == second_row[1]);
  REQUIRE(face_color[row][2] == second_row[2]);

  // Check for third row
  row++;
  Color *third_row{face.GetIthRow(row)};
  REQUIRE(face_color[row][0] == third_row[0]);
  REQUIRE(face_color[row][1] == third_row[1]);
  REQUIRE(face_color[row][2] == third_row[2]);

  delete first_row;
  delete second_row;
  delete third_row;

  // Check for first column
  int column = 0;
  Color *first_column{face.GetIthColumn(column)};
  REQUIRE(swapped_row[0] == first_column[0]);
  REQUIRE(face_color[1][column] == first_column[1]);
  REQUIRE(face_color[2][column] == first_column[2]);

  // Check for second column
  column++;
  Color *second_column{face.GetIthColumn(column)};
  REQUIRE(swapped_row[1] == second_column[0]);
  REQUIRE(face_color[0][column] == second_column[1]);
  REQUIRE(face_color[2][column] == second_column[2]);

  // Check for third row
  column++;
  Color *third_column{face.GetIthColumn(column)};
  REQUIRE(swapped_row[2] == third_column[0]);
  REQUIRE(face_color[1][column] == third_column[1]);
  REQUIRE(face_color[2][column] == third_column[2]);

  delete first_column;
  delete second_column;
  delete third_column;
}

// Initialize and swap third column, and then check all the rows and columns.
TEST_CASE("TestSwapColumns", "[SwapColumns, GetRows, GetColumns]") {
  Color face_color[3][3];
  srand(time(0));
  // Initialize a face with all the same colors.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      face_color[i][j] = Color::Color1;
    }
  }

  Face face(face_color, FacePosition::Up);

  // Swap first row with another row.
  Color swapped_column[] = {Color::Color1, Color::Color2, Color::Color3};
  
  face.SwapIthColumn(swapped_column, 2);

  face.PrintFace();
  // Check for first row
  int row = 0;
  Color *first_row{face.GetIthRow(row)};
  REQUIRE(face_color[row][0] == first_row[0]);
  REQUIRE(face_color[row][1] == first_row[1]);
  REQUIRE(swapped_column[0] == first_row[2]);

  // Check for second row
  row++;
  Color *second_row{face.GetIthRow(row)};
  REQUIRE(face_color[row][0] == second_row[0]);
  REQUIRE(face_color[row][1] == second_row[1]);
  REQUIRE(swapped_column[1] == second_row[2]);

  // Check for third row
  row++;
  Color *third_row{face.GetIthRow(row)};
  REQUIRE(face_color[row][0] == third_row[0]);
  REQUIRE(face_color[row][1] == third_row[1]);
  REQUIRE(swapped_column[2] == third_row[2]);

  delete first_row;
  delete second_row;
  delete third_row;

  // Check for first column
  int column = 0;
  Color *first_column{face.GetIthColumn(column)};
  REQUIRE(face_color[0][column] == first_column[0]);
  REQUIRE(face_color[1][column] == first_column[1]);
  REQUIRE(face_color[2][column] == first_column[2]);

  // Check for second column
  column++;
  Color *second_column{face.GetIthColumn(column)};
  REQUIRE(face_color[0][column] == second_column[0]);
  REQUIRE(face_color[0][column] == second_column[1]);
  REQUIRE(face_color[2][column] == second_column[2]);

  // Check for third row
  column++;
  Color *third_column{face.GetIthColumn(column)};
  REQUIRE(swapped_column[0] == third_column[0]);
  REQUIRE(swapped_column[1] == third_column[1]);
  REQUIRE(swapped_column[2] == third_column[2]);

  delete first_column;
  delete second_column;
  delete third_column;
}

} // namespace rubiks