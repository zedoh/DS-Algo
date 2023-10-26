#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

typedef vector<vector<int>> GRAPH; 

void  AddEdge(GRAPH& graph, int from, int to) {
	graph[from].push_back(to); 
}

void print(GRAPH& graph) {
	int size = graph.size();
	for (int i = 0; i < size; ++i) {
		cout << "Node from " << i << " has neighbors: "; 
		for (int j = 0; j < (int)graph[i].size(); ++j) {
			cout << graph[i][j]<<" ";
		}
		cout << '\n'; 
	}
}

void PrintChain(GRAPH& graph, int from) {
	cout << from << " "; 
	if(!graph[from].empty()){
		PrintChain(graph,graph[from][0]); 
	}
	cout << "\n"; 
}

void Queries(GRAPH &graph , int NumberofQueries) {
	cout << "Enter your queries \n";
	while (NumberofQueries--) {
		int nodes; 
		cin >> nodes; 
		PrintChain(graph, nodes); 
		cout << '\n'; 
	}
}


int main() {
	int nodes, edges; 
	cout << "Enter number of nodes and edges: ";
	cin >> nodes >> edges; 
	GRAPH graph(nodes, vector<int>()); 
	int from, to; 
	for (int i = 0; i < edges; ++i) {
		cin >> from >> to; 
		AddEdge(graph, from, to); 
	}
	print(graph); 
	cout << "\n"; 
	int q; //Number of queries
	cout << "Enter number of queries: ";
	cin >> q; 
	Queries(graph, q); 


	return 0; 
}
