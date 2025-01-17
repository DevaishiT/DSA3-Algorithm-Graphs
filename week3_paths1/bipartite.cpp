#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here

  //vector<bool> visit(adj.size(), false);
  vector<int> group(adj.size(), 0); // 1 and 2 are the groups
  queue<int> q;

  group[0] = 1;
  q.push(0);

  int v;
  while (!q.empty())
  {
    v = q.front();
    q.pop();

    for (auto x : adj[v])
    {
      if (group[x] != 0)
      {
        if (group[x] == group[v]) return 0;
      }
      else
      { 
        if (group[v] == 1) group[x] = 2;
        else group[x] = 1;
        q.push(x);  
      } 
    }
  }

  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
