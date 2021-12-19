#pragma once

#include <string>

// A Vector2 that hold two integer values
class Vector2 {
public:
  // Position variables
  int x;
  int y;

  // ---- Constructors ----
  Vector2() : x(0), y(0){};
  ~Vector2() {};
  Vector2(int x, int y);

  // Returns the euclidian distance between two vectors
  static double distance(const Vector2& vector1, const Vector2& vector2);
};
