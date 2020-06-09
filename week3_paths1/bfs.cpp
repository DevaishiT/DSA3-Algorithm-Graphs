#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here

  	if (s == t) return 0;
  	vector<bool> visit(adj.size(), false);
  	vector<int> dist(adj.size(), -1);
  	queue<int> q;

  	visit[s] = true;
  	dist[s] = 0;
  	q.push(s);

  	int v;
  	while (!q.empty())
  	{
		v = q.front();
		q.pop();

		for (auto x : adj[v]) 
		{
			if (x == t) return (dist[v] + 1);
			if (!visit[x]) 
			{ 
				visit[x] = true;
				dist[x] = dist[v] + 1;
				q.push(x);	
			}	
		}
	}
	return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
