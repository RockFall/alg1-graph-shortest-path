#pragma once

#include <vector>

// Disjoint Set Union
// Usable for detecting the cycles on the graph in O(LogV)
class DSU {
public:
  // Initializes both vectors with size N and fills tham with parent(-1), rank(1)
  DSU(int N);

  // Determines the subset a vertice is in recursively
  int Find(int v);
  // Joins two subsets into one if not already together
  void Unite(int v1, int v2);
private:
  std::vector<int> parents_;
  std::vector<int> ranks_;
};
