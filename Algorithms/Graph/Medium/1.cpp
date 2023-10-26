#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std; 


struct edge {
	string to; 
	int cost; 
	
	edge( string to , int cost) :  to(to) , cost(cost){}

	bool operator <(const edge&other)const {
		if (other.to != to) {
			return to < other.to; 
		}
		return cost < other.cost; 
	}
};

typedef map<string,multiset<edge>> GRAPH; 


void add_directed(GRAPH& graph, string from, string to, int cost) {
	graph[from].insert({ to,cost }); 
}


void print(GRAPH &graph) {
	for (auto& node : graph) {
		cout << "Flights from " << node.first << ": \n"; 
		for (const edge& e : node.second) {
			cout << "\tTo " << e.to << " with cost " << e.cost << '\n'; 
		}
	}
}

int main() {
	int nodes, edges; 
	cin >> nodes >> edges; 
	GRAPH graph; 

	for (int e = 0; e < edges; ++e) {
		string from, to; 
		int cost;
		cin >> from >> to >> cost; 
		add_directed(graph, from, to, cost); 
	}
	print(graph); 
	return 0; 
}

