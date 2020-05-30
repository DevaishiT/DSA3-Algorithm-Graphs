#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore_vertex(const vector<vector<int>> &adj, vector<bool> &visit, int v, vector<int> &post_order)
{
	visit[v] = true;
	for (auto x : adj[v])
		if (!visit[x]) explore_vertex(adj, visit, x, post_order);
	post_order.push_back(v);
}

void explore_vertex(const vector<vector<int>> &adj, vector<bool> &visit, int v)
{
	visit[v] = true;
	for (auto x : adj[v])
		if (!visit[x]) explore_vertex(adj, visit, x);
}

vector<int> reverse_graph_topological_sort( const vector<vector<int>> &adj )
{
	vector<vector<int> > adj2(adj.size(), vector<int>());
	for(int v=0; v<adj.size(); v++)
		for (auto x : adj[v]) adj2[x].push_back(v);
	
	vector<bool> visit(adj2.size(), false);
	vector<int> v;

	for (int i=0; i<adj2.size(); i++)
		if (!visit[i]) explore_vertex(adj2, visit, i, v);

	reverse(v.begin(), v.end());
	return v;
}

int number_of_strongly_connected_components(const vector<vector<int> > &adj) {
  int result = 0;
  //write your code here
  vector<int> v = reverse_graph_topological_sort(adj);
  vector<bool> visit(adj.size(), false);
  for(int i=0; i<adj.size(); i++)
  {
	 if (visit[v[i]]) continue;
	 result++;
	 explore_vertex(adj, visit, v[i]);
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
