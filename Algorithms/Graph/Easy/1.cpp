#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge {
	int from, to, weight;

	edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}

	bool operator < (const edge& e) const {
		return weight < e.weight;
	}

	void print() {
		cout << "Edge (" << from << " " << to << " " << weight << ")\n";
	}
};

typedef vector<edge> GRAPH;

void add_edge(GRAPH& graph, int from, int to, int cost) {
	graph.push_back({from,to,cost});
}

void print_adjaceny_matrix(GRAPH& graph) {
	for (int edge = 0; edge < (int)graph.size(); ++edge)
		graph[edge].print();
}

//int main() {
//	int nodes, edges;
//	cout << "\nEnter number of nodes and edges: "; 
//	cin >> nodes >> edges;
//
//	GRAPH graph;
//
//	for (int e = 0; e < edges; ++e) {
//		int from, to, cost;
//		cin >> from >> to >> cost;
//		add_edge(graph, from, to, cost);
//	}
//	sort(graph.begin(), graph.end());
//	print_adjaceny_matrix(graph);
//	return 0;
//}
