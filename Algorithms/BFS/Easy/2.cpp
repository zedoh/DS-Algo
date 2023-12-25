#include <iostream>
#include <vector>
#include <iostream>
#include <queue>
using namespace std; 


typedef vector<vector<char>> GRAPH;
const int OO = 10000000; 

void build_undirected(GRAPH& graph, int from, int to) {
	graph[from].push_back(to); 
	graph[to].push_back(from); 
}

bool BFSCycle(GRAPH& graph, int start, vector<int>& len, vector<int>& parent) {
	queue<int>q; 
	q.push(start);
	len[start] = 0; 

	for (int level = 0, sz = 1; !q.empty(); sz = q.size(), ++level) {
		while (sz--) {
			int cur = q.front(); 
			q.pop(); 
			for (auto& neighbour : graph[cur]) {
				if (neighbour == parent[cur])
					continue; 
				if (len[neighbour] == OO) {
					q.push(neighbour); 
					parent[neighbour] = cur; 
					len[neighbour] = level + 1; 
				}
				else
					return true; 
			}
		}
	}
	return false; 
}


bool has_cycle(GRAPH& graph) {
	int nodes = graph.size(); 
	vector<int> len(nodes, OO); 
	vector<int>parent(nodes, -1); 

	for (int i = 0; i < nodes; ++i) {
		if (len[i] == OO && BFSCycle(graph, i, len, parent))
			return true; 
	}
	return false; 
}

bool validTree(int nodes, GRAPH& edges) {
	if ((int)edges.size() != nodes - 1)
		return false; 

	GRAPH graph(nodes); 

	for (auto& e : edges) {
		build_undirected(graph, e[0], e[1]); 
	}

	return !has_cycle(graph); 
}
