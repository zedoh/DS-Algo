#include <iostream>
#include <vector>
#include <cstring>
#include <memory>
#include <algorithm>
#include <climits>
using namespace std ;
/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
    public:
        
        int mem[200][200*100+1];
        vector<int> numlist;

    bool FindPartition(int idx ,int target){
        if(target < 0) return false; 
        if(idx == numlist.size())   return false;
        if(target == 0) return true; 
        auto &ret  = mem[idx][target] ; 
        if(ret != -1)   return ret ; 
        if (FindPartition(idx+1 , target))
            return ret = true ; 
        return ret = FindPartition(idx+1 , target - numlist[idx]); 
    }
    
    bool canPartition(vector<int>& nums) {
        memset(mem, -1, sizeof(mem)) ; 
        numlist = nums ; 
        int total = accumulate(numlist.begin() , numlist.end() , 0) ; 
        if(total % 2 != 0) return false; 
        return FindPartition(0,total/2) ; 
    }
};
// @lc code=end

