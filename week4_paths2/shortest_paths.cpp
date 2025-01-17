#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  queue<int> q;
  distance[s] = 0;
  reachable[s] = 1;
  for(int t=0; t<adj.size(); t++)
  {
    for(int i=0; i<adj.size(); i++)
    {
      for(int j=0; j<adj[i].size(); j++)
      {
        int v = adj[i][j];

        if (distance[i]!= std::numeric_limits<long long>::max() && distance[v] > distance[i] + cost[i][j]) 
        {
          if (!reachable[v]) reachable[v] = 1;
          distance[v] = distance[i] + cost[i][j];
          if (t == adj.size() - 1) q.push(v);
        }
      }
    }
  }

  vector<int> visited(adj.size(), 0);
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    visited[u] = 1;
    shortest[u] = 0;
    for (int i = 0; i < adj[u].size(); i++) 
    {
      int v = adj[u][i];
      if (!visited[v]) 
      {
        q.push(v);
        visited[v] = 1;
        shortest[v] = 0;
      }
    }
  }
  distance[s] = 0;
  shortest[s] = 1;
  return;
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
