#pragma once

#include "Vector2.hpp"

class Store {
public:
  // --- Constructor ---
  Store();
  ~Store();

  // Getters & Setters
  int getID();

  // Turn this class into a debug string
  operator std::string() const {
    return std::to_string(id_) + " " + std::to_string(position_.x) + " " + std::to_string(position_.y);
  }

private:
  int id_;
  Vector2 position_;
};
