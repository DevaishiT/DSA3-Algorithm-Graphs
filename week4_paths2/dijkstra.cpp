#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
#include <functional>

using namespace std;

typedef pair<long, int> int_pair;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code here

	vector<long> dist(adj.size(), INT_MAX);
	// vector<int> previous(size, -1);
	vector<bool> visited(adj.size(), false);

	priority_queue <int_pair, vector<int_pair>, greater<int_pair> > pq; 

	dist[s] = 0;
	pq.push(make_pair(0, s));

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		if (u == t) return dist[t];

		if (!visited[u]) visited[u] = true;
		else continue;

		for(int i=0; i<adj[u].size(); i++)
		{
			if (dist[adj[u][i]] > dist[u] + cost[u][i])
			{
				dist[adj[u][i]] = dist[u] + cost[u][i];
				pq.push(make_pair(dist[adj[u][i]], adj[u][i]));
			}
		}
	}
  	if (dist[t] == INT_MAX) return -1;
  	else return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
