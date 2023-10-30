#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std ; 

// LeetCode problem: <https://leetcode.com/problems/employee-importance/submissions/1085951251/>

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
    private: 
   unordered_map<int,Employee*>id_emp; 
public:
    int getImportance(vector<Employee*> employees, int id) {
       for(auto &emp : employees){
           id_emp[emp->id] = emp ; 
       } 
       return dfs(id) ; 
    }

    int dfs(int id){
        Employee* emp =  id_emp[id] ; 
        int result = emp->importance ; 
        for(auto sub : emp->subordinates){
            result += dfs(sub) ; ;
        }
        return result  ; 
    }
};