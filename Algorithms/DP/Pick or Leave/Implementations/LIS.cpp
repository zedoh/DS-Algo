#include <vector>
#include <cmath>
#include <iostream>

using namespace std ; 

vector<int> numlist ;
const int MAX {2500+1} ; 
int mem[MAX][MAX] ; 

int LIS (int idx , int prev = (int)numlist.size()){
    if(idx == (int)numlist.size()){
        return 0 ; 
    }
    auto &ret = mem[idx][prev];
    if(ret!=-1){
        return ret ;
    }

    int choice1 = LIS(idx+1,prev) ;  // Leave the current idx
    int choice2 = 0 ; 

    if(prev>=(int)numlist.size() || numlist[prev]  < numlist[idx]){
        choice1 = LIS(idx+1,idx)+1 ; 
    }
    return ret = max(choice2,choice1) ; 
}
