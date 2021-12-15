#pragma once

class Edge {
public:
  double weight;
  int from, to;

  Edge() : weight(0), from(0), to(0) { }; // default
  Edge(double w, int f, int t) : weight(w), from(f), to(t){ }; // custom constructor
  Edge(const Edge &e) : weight(e.weight), from(e.from), to(e.to) { }; // copy constructor
  ~Edge(){ }; // destructor
};
