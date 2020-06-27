#include <iostream>
#include <vector>
#include <climits>

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here

  vector<long> dist(adj.size(), INT_MAX);
  dist[0] = 0;
  for(int t=0; t<adj.size(); t++)
  {
    for(int i=0; i<adj.size(); i++)
    {
      for(int j=0; j<adj[i].size(); j++)
      {
        int v = adj[i][j];
        if (dist[v] > dist[i] + cost[i][j]) 
        {
          dist[v] = dist[i] + cost[i][j];
          if (t == adj.size() - 1) return 1;
        }
      }
    }
  }

  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
