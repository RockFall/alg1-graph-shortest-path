#include "SupplyPathFinder.hpp"

#include <iostream>
#include <algorithm>

#include "Vector2.hpp"
#include "DSU.hpp"

SupplyPathFinder::SupplyPathFinder() : storeCount_(0), bikeKMlimit_(0), dronesCount_(0), bikeCost_(0), truckCost_(0), edges() {

}

SupplyPathFinder::SupplyPathFinder(int N, int K, int D, int M, int C) : storeCount_(N), bikeKMlimit_(K), dronesCount_(D), bikeCost_(M), truckCost_(C), edges() {

}

SupplyPathFinder::~SupplyPathFinder() {

}

void SupplyPathFinder::Populate()
{
  // Initial inputs
  std::cin >> storeCount_ >> bikeKMlimit_ >> dronesCount_ >> bikeCost_ >> truckCost_;

  Vector2 stores[storeCount_];
  // for each store on input, adds it's edge to every other store
  for (int i = 0; i < storeCount_; ++i)
  {
    int x, y;
    std::cin >> x >> y;
    Vector2 pos = Vector2(x, y);

    for (int j = 0; j < i; j++)
    {
      double dst = Vector2::distance(pos, stores[j]);
      edges.push_back(Edge(dst, i, j));
    }
    stores[i] = pos;
  }
}

void SupplyPathFinder::AddEdge(double weight, int from, int to) {
  edges.push_back(Edge(weight, from, to));
}

std::pair<double, double> SupplyPathFinder::Find(){
  // Find MST
  std::priority_queue<double> MSTWeights = KruskalMST();

  // Final variables
  double truckKM = 0;
  double motorcycleKM = 0;

  // First 'dronesCount_'-1 edges are removed from priorityqueue
  for (int i = 0; i < dronesCount_ - 1; i++)
  {
    MSTWeights.pop();
  }

  // Now we get truck's edges until we hit one with distance less the motorcycle limit
  while (!MSTWeights.empty() && MSTWeights.top() > bikeKMlimit_)
  {
    truckKM += MSTWeights.top();
    MSTWeights.pop();
  }

  // The rest of the priority_queue are motorcycle's edges
  while (!MSTWeights.empty()){
    motorcycleKM += MSTWeights.top();
    MSTWeights.pop();
  }
  // Return KM * cost
  return std::make_pair(motorcycleKM * bikeCost_, truckKM * truckCost_);
}

std::priority_queue<double> SupplyPathFinder::KruskalMST() {
  // Sorting all edges based on weight
  std::sort(edges.begin(), edges.end(), [](const Edge &e1, const Edge &e2) -> bool
            { return e1.weight < e2.weight; });

  // Creating disjoint set union to check for cycles
  DSU dsu(storeCount_);

  // Priority queue hold's the resulting weights of each edge on the final MST
  std::priority_queue<double> MSTWeights;

  for(auto& edge : edges)
  {
    // If not in the same subset -> don't form cycle
    if (dsu.Find(edge.from) != dsu.Find(edge.to)) {
      // Adds it to MST
      dsu.Unite(edge.from, edge.to);
      MSTWeights.push(edge.weight);
      //std::cout << "New edge to MST:" << edge.from << "-" << edge.to << " w=" << edge.weight << std::endl;
    }
  }

  return MSTWeights;
}
