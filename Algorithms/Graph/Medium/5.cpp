#include <iostream>
#include <vector>
using namespace std; 

typedef vector<vector<int>> GRAPH;

void AddEdge(GRAPH& graph, int from, int to) {
	graph[from].push_back(to); 
}

void print(GRAPH& graph) {
	for (int i = 0; i < (int)graph.size(); ++i) {
		cout << i << "\t"; 
		for (int j = 0; j < graph[i].size(); ++j) {
			cout << graph[i][j]<<" ";
		}
		cout << "\n"; 
	}
	
}

void print_paths_len_2(GRAPH& graph) {
	int nodes = graph.size();
	for (int i = 0; i < nodes; ++i) {
		for (int j = 0; j < graph[i].size(); ++j) {
			int first = graph[i][j]; 
			for (int k = 0; k < graph[first].size(); ++k) {
				int second = graph[first][k]; 
				cout << i << " " << first << " " << second << '\n'; 
			}
		}
	}
}

int main() {
	int nodes, edges; 
	cout << "Enter number of nodes and edges: "; 
	cin >> nodes >> edges; 
	GRAPH graph(nodes); 
	int from, to; 
	for (int e = 0; e < edges; e++) {
		cin >> from >> to; 
		AddEdge(graph, from, to); 
	}
	//print(graph); 
	print_paths_len_2(graph); 
}
