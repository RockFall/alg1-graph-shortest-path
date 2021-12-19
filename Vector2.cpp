#include "Vector2.hpp"

#include <cmath>

Vector2::Vector2(int x, int y)
{
  this->x = x;
  this->y = y;
}

double Vector2::distance(const Vector2& vector1, const Vector2& vector2) {
  return std::sqrt((vector1.x - vector2.x) * (vector1.x - vector2.x) + (vector1.y - vector2.y) * (vector1.y - vector2.y));
}
