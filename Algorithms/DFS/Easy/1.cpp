#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std; 
typedef unordered_map<int , vector<int>> GRAPH; 

void add_edge(GRAPH& graph, int from, int to) {
	graph[from].push_back(to); 
}

void BuildGraph(GRAPH& graph, vector<int>& pid, vector<int>& ppid) {
	for (int i = 0; i < (int)pid.size(); ++i) {
		add_edge(graph, ppid[i],pid[i]); 
	}
}

void dfs(GRAPH& graph, unordered_set<int>& visited, int node) {
	visited.insert(node); 
	for (auto neighbour : graph[node]) {
		if(!visited.count(neighbour))
			dfs(graph, visited, neighbour); 
	}
}

vector<int> Reachability(GRAPH& graph, int node) {
	unordered_set<int> visited; 
	dfs(graph, visited, node); 
	return vector<int>(visited.begin(), visited.end()); 
}
vector<int> KillProcess(vector<int>& pid, vector<int>& ppid, int kill) {
	GRAPH graph; 
	BuildGraph(graph, pid, ppid);
	return Reachability(graph, kill); 
}
