// Leetcode 323 : <https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/>

#include <iostream>
#include <vector>
using namespace std; 

int countComponents(int n, vector<vector<int>>& edges) {
	vector<bool> visited(n, false); 
	int counter{ 0 }; 
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			++counter; 
			dfs(visited, edges, i); 
		}
	}
	return counter; 
}

void dfs(vector<bool>& visited, vector<vector<int>>& edges, int StartingPoint) {
	visited[StartingPoint] = 1; 
	for (int n : edges[StartingPoint]) {
		if (!visited[n]) {
			dfs(visited, edges, n); 
		}
	}
}
