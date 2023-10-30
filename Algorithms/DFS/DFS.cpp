#include <iostream>
#include <vector>
using namespace std ; 
typedef vector<vector<int>> GRAPH ; 

void dfs(GRAPH& graph, int node, vector<bool>& visited) {
	visited[node] = 1; 

	for (int neighbour : graph[node]) {
		if (!visited[neighbour]) {
			cout << "\tWe can reach " << neighbour << "\n";
			dfs(graph, neighbour, visited); 
		}
	}
}

void reachability(GRAPH& graph) {
	int nodes = graph.size(); 
	for (int i = 0; i < nodes; ++i) {
		vector<bool>visited(nodes); 
		cout << "Reachable set of node " << i << '\n'; 
		dfs(graph, i, visited); 
	}
}
