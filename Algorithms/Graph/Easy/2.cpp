#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std; 

typedef vector<unordered_set<int>> GRAPH; 

void  add_edge(GRAPH &graph  , int from ,int to) {
	graph[from].insert(to); 
}

void print(GRAPH& graph) {
	for (int i = 0; i < (int)graph.size(); ++i) {
		if (graph[i].empty()) {
			cout << "\nFrom: " << i << " no edges\n";
			continue; 
		}
		cout << "\nFrom: " << i << " to: "; 
		for (auto j : graph[i]) {
			cout << j << '\t'; 
		}
		cout << '\n'; 
	}
}

//int main() {
//	int nodes, edges; 
//	cout << "\nEnter number of nodes and edges: "; 
//	cin >> nodes >> edges;
//	GRAPH graph(nodes); 
//	int from, to; 
//	for (int i = 0; i < edges; ++i) {
//		cout << "\nFrom: "; 
//		cin >> from; 
//		cout << "\nto: "; 
//		cin >> to; 
//		add_edge(graph, from, to); 
//	}
//	print(graph); 
//}
