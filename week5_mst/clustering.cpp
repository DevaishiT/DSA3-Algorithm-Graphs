#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

class disjointSet {
private:
  int *rank, *parent, n;

public:
  disjointSet(int num)
  {
    this->rank = new int[num];
    this->parent = new int[num];
    this->n = num;
    for(int i=0; i<n; i++)
      makeSet(i);
  }
  void makeSet(int i)
  {
    parent[i] = i;
    rank[i] = 0;
  }
  int find(int i)
  {
    if (i != parent[i])
      parent[i] = find(parent[i]);
    return parent[i];
  }
  void Union(int i, int j)
  {
    int i_id = find(i);
    int j_id = find(j);
    if (i_id == j_id) return;
    if (rank[i_id] > rank[j_id])
      parent[j_id] = i_id;
    else parent[i_id] = j_id; 
    if (rank[i_id] == rank[j_id])
      rank[j_id]++;
    return; 
  }
};

class edge {
public:
  int source, target;
  double weight;

  edge(int u, int v, double w) {
    source = u;
    target = v;
    weight = w;
  }
};

class graph {
  int size;
  vector<edge> edges;
public:
  graph(int num) {
    size = num;
  }
  void add_edge(int u, int v, double w);
  double min_weight(int k);
};

void graph::add_edge(int u, int v, double w) 
{ 
  edges.push_back(edge(u, v, w));
  edges.push_back(edge(v, u, w));
} 

bool compare (edge e1, edge e2)
{
  return (e1.weight < e2.weight);
}

double graph::min_weight(int k)
{
  disjointSet dj(size);
  int count = 0;

  sort(edges.begin(), edges.end(), compare);

  for(auto e : edges)
  {
    if (dj.find(e.source) != dj.find(e.target))
    {
      count++;
      dj.Union(e.source, e.target);
    }
    if (count > size - k) return e.weight;
  }

  return -1;
}

double get_weight(int x1, int y1, int x2, int y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double clustering(vector<int> x, vector<int> y, int k) {
  
  //write your code here
  graph g(x.size());

  for(int i=0; i<x.size(); i++)
    for(int j=i+1; j<x.size(); j++)
      g.add_edge(i, j, get_weight(x[i], y[i], x[j], y[j]));

  return g.min_weight(k);

  return -1.;
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
