#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int reach_rec(vector<bool> &visited, vector<vector<int> > &adj, int x, int y)
{
  if (x == y) return 1;
  visited[x] = true;
  for (auto v : adj[x]) {
    if (!visited[v]) 
      if (reach_rec(visited, adj, v, y)) return 1;

  }
  return 0;
}

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  vector<bool> visited(adj.size(), false);
  return reach_rec(visited, adj, x, y);
  //return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
