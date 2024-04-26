// Leetcode : https://leetcode.com/problems/min-cost-climbing-stairs/submissions/1232144204/
 
vector<int> stairs ;
class Solution {
public:
    int mem[1000] ; 
    int climb(int idx){
        if(idx >= (int)stairs.size())   return  0 ; 
        auto &ret = mem[idx] ; 
        if(~ret)    return ret ;
        //choices
        int climb_one = stairs[idx] + climb(idx+1) ; 
        int climb_two = stairs[idx] + climb(idx+2) ; 

        return ret = min(climb_one, climb_two) ;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(mem , -1 , sizeof(mem)) ; 
        stairs = cost ;
        return min(climb(0) , climb(1)) ; 
    }
};