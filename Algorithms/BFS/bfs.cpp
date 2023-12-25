#include <iostream>
#include <vector>
#include <queue>
using namespace std ; 
typedef vector<vector<int>> GRAPH ; 

const long long OO {1000000}  ;
vector<int>BFS(GRAPH &graph,int start){
    vector<int>len (graph.size(),OO)  ; 
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
                }
            }
        }
    }
    return len;
}