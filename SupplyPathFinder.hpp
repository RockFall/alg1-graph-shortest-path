#pragma once

#include <iostream>
#include <vector>
#include <queue>

#include "Edge.hpp"

class SupplyPathFinder
{
public:
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
