/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start

enum {
    IDLE = 0 ,
    BUY = 1 , 
    SELL = 2
} ; 
class Solution {
public:
    static const int MAX{5001} ; // Leetcode constrain
    int mem[MAX][2][3] ;
    vector<int> numlist;

    int findProfit(int idx ,int haveStock , int transactionState){
        if(idx == (int)numlist.size())  return 0 ; 
        auto &ret = mem[idx][haveStock][transactionState];
        if(ret != -1)   return ret ; 
        int noTrade = findProfit(idx+1 , haveStock , 0) ; 
        int buy = 0 ,  sell = 0 ; 
        if(haveStock){
            sell = numlist[idx] +  findProfit(idx+1 , 0 , SELL) ; 
        }else if(transactionState != SELL){
            buy = -numlist[idx] + findProfit(idx+1 , 1 , BUY) ; 
        }

        return ret = max(max(sell,buy),noTrade) ; 
    }

    int maxProfit(vector<int>& prices) {
        memset(mem,-1,sizeof(mem)) ; 
        numlist = prices ; 
        return findProfit(0,0,0) ;         
    }
};
// @lc code=end

