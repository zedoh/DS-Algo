vector<int> money; 
class Solution {
public:
    int mem[301][5001] ;
    int splitMoney(int idx,int amount){
        if(amount == 0)
            return 1 ; 
        if(amount < 0)
            return 0 ;
        if(idx == (int)money.size())
            return 0 ;  

        auto &ret = mem[idx][amount] ; 
        if(ret != -1)
            return ret; 
        
        int pick = 0 , leave = 0 ; 
        pick  =   splitMoney(idx , amount-money[idx]);
        leave =   splitMoney(idx+1 , amount) ; 
        return ret = pick + leave ; 
    } 
    int change(int amount, vector<int>& coins) {
        money = coins ;
        memset(mem , -1 ,sizeof(mem)) ; 
        return splitMoney(0 , amount) ;         
    }
};