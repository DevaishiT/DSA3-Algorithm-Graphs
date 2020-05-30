#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool explore(vector<vector<int> > &adj, vector<bool> &visit, vector<bool> &path, int v)
{
  visit[v] = true;
  path[v] = true;
  // cout << v << " ";
  for (auto x : adj[v])
  {
    if (visit[x] and path[x]) return true;
    else if (!visit[x] and explore(adj, visit, path, x))
      	return true;
  }
  path[v] = false;
  return false;
}

bool acyclic(vector<vector<int> > &adj) {
  //write your code here
  vector<bool> visit(adj.size(), false);
  vector<bool> path(adj.size(), false);
  for (int i=0; i<adj.size(); i++)
  {
    if (visit[i]) continue;
    if (explore(adj, visit, path, i))
      return true;
  }
  return false;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
