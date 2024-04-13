/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start

vector<int> houses ; 

class Solution {
public:
    int mem1[101] ;
    int mem2[101] ; 
     
    int steal1(int idx){
        if(idx < 0 )    return 0 ; 
        auto &ret = mem1[idx] ; 
        if(ret != -1) return ret ;

        return ret  = max(houses[idx]+steal1(idx-2) , steal1(idx-1)) ; 
    }

    int steal2(int idx){
        if(idx < 1 )    return 0 ; 
        auto &ret = mem2[idx] ; 
        if(ret != -1) return ret ;

        return ret  = max(houses[idx]+steal2(idx-2) , steal2(idx-1)) ;
    }
    int rob(vector<int>& nums) {
        memset(mem1 , -1 , sizeof(mem1)) ; 
        memset(mem2 , -1 , sizeof(mem2)) ; 
        houses = nums ;
        int sz = houses.size() ; 
        if(sz == 1) return houses[0] ; 
        return max(steal1(sz-2) , steal2(sz-1)) ; 
    }
};
// @lc code=end

