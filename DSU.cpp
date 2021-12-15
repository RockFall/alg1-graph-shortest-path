#include "DSU.hpp"

DSU::DSU(int N) : parents_(N, -1), ranks_(N, 1) {

}

int DSU::Find(int v){
  if (parents_[v] == -1) {
    return v;
  }
  return parents_[v] = Find(parents_[v]);
}

void DSU::Unite(int v1, int v2) {
  int s1 = Find(v1);
  int s2 = Find(v2);

  if (s1 != s2) {
    if (ranks_[s1] < ranks_[s2]){
      parents_[s1] = s2;
      ranks_[s2] += ranks_[s1];
    } else {
      parents_[s2] = s1;
      ranks_[s1] += ranks_[s2];
    }
  }
}
