#include "DSU.hpp"

DSU::DSU(int N) : m_parents(N, -1), m_ranks(N, 1) {

}

int DSU::Find(int v){
  if (m_parents[v] == -1) {
    return v;
  }
  return m_parents[v] = Find(m_parents[v]);
}

void DSU::Unite(int v1, int v2) {
  int s1 = Find(v1);
  int s2 = Find(v2);

  if (s1 != s2) {
    if (m_ranks[s1] < m_ranks[s2]){
      m_parents[s1] = s2;
      m_ranks[s2] += m_ranks[s1];
    } else {
      m_parents[s2] = s1;
      m_ranks[s1] += m_ranks[s2];
    }
  }
}
