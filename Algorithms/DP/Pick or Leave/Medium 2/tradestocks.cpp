#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std  ;


vector<int>numbers ; 
const int MAX {2501} ;
int mem[MAX][2][3];

enum{
    BUY = 2 , SELL = 1 , NOTHING = 0 
};

int trade(int idx, bool has_stock,int currentstate ){
    if(idx == (int)numbers.size()) 
        return 0;

    auto &ret = mem[idx][has_stock][currentstate] ; 
    if(ret != -1)
        return ret;

    int do_nothing = trade(idx+1,has_stock , NOTHING) ;
    int buy  = 0 , sell = 0 ; 

    if(has_stock)
        sell = numbers[idx] + trade(idx+1,0,SELL) ; 
    else if(currentstate != SELL) 
        buy = -numbers[idx] + trade(idx+1 , 1 ,BUY) ; 
    
    return ret = max(max(buy,sell),do_nothing) ; 
}

int maxProfit(vector<int>& prices){
    return trade(0,0,NOTHING) ; 
}
int main(){
    numbers =  {1,2,3,0,2} ; 
    memset(mem,-1,sizeof(mem)) ;
    cout<<maxProfit(numbers)<<'\n';
    return 0 ; 
}

