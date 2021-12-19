#pragma once

#include <iostream>
#include <vector>
#include <queue>

#include "Edge.hpp"

// Must be populated from std::cin input with Populate()
// Finds the total distance for trucks and bikes in the best
// arrangement of paths from all paths possible between stores
class SupplyPathFinder
{
public:
  // ---- CONSTRUCTORS ----
  SupplyPathFinder();
  SupplyPathFinder(int N, int K, int D, int M, int C);
  ~SupplyPathFinder();

  // Populates the system with input of stores
  void Populate();
  // Adds an Edge into the stores graph
  // -> USED FOR TESTING
  void AddEdge(double weight, int from, int to);

  // Finds and returns the optimal KM's for motorcycles and trucks
  std::pair<double, double> Find();

private:
  // Applies Kruskal's algorithm on the internal
  // graph and return the MST found
  std::priority_queue<double> KruskalMST();

  // Total number of stores
  int storeCount_;
  // The maximum Km's that a motorcycle can go
  int bikeKMlimit_;
  // The amount of drones available
  int dronesCount_;
  // The cost per KM for motorcycles
  int bikeCost_;
  // The cost per KM for trucks
  int truckCost_;

  // The graph of stores as a adjacency list of edges
  std::vector<Edge> edges;
};
