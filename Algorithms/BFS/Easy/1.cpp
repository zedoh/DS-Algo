#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <utility>
#include <fstream>

using namespace std ; 

typedef vector<vector<int>> GRAPH ; 

void build_graph(GRAPH &graph , int from ,int to){
    graph[from].push_back(to);
}

void print_graph(GRAPH &graph , vector<int>&level){
    int nodes = graph.size() ; 
    for(int i = 0 ; i < nodes ; ++i){
        cout<<"\nFrom: "<<i<<": " ; 
        for(size_t  j = 0 ; j < graph[i].size(); ++j){
            cout<<graph[i][j]<<" " ; 
        }
        cout<<" with a level of "<<level[i]<<'\n' ; 
    }
}

const long long OO {1000000}  ;
vector<int>BFS(GRAPH &graph,int start){
    vector<int>len (graph.size(),OO)  ; 
    vector<int>parent(graph.size(), -1) ; 
    queue<int>q  ;
    q.push(start);
    len[start] = 0 ; 
    for(int sz = 1, level = 0   ; !q.empty() ; ++level,sz=q.size()){
        while(sz--){
            int curr = q.front() ; 
            q.pop() ; 
            for(auto &neighbour : graph[curr]){
                if(len[neighbour] == OO){
                    q.push(neighbour) ; 
                    len[neighbour] = level+1; 
                    parent[neighbour] = curr ; 
                }
            }
        }
    }
    return parent;
}

void print_path(vector<int>& parent,int curr){
    if(curr == -1)
        return ; 
    print_path(parent,parent[curr]) ; 
    cout<<curr<<" " ; 
}


int main(){
    int t ; 
    cin>>t ; 
    while(t--){
        int nodes , edges ; 
        cout<<"\nEnter number of nodes and edges: " ; 
        cin>>nodes >>edges   ;
        GRAPH graph(nodes) ; 
        int from , to ; 
        for(int i = 0 ; i < edges ; ++i){
            cin>>from>>to;
            build_graph(graph,from,to) ;
        } 
        int start = 0 ; 
        vector<int>parent = BFS(graph,start) ; 
        for(int i =0 ; i < nodes  ; ++i){
            if(start == i)
                continue;
            cout<<"\nPath from: "<<start<<" to: "<<i<<": " ; 
            if(parent[i] == -1){
                cout<<"Not Exist" ; 
            }else{
                print_path(parent,i); 
            }
            cout<<'\n' ; 
        }

        cout << '\n';
    }
    return 0 ; 
}