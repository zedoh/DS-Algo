#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;  


vector<int> numList ;
const int MAX {2501} ; 
int mem[MAX] ; 

int LIS(int idx){

    if(idx == (int)numList.size()){
        return 0;
    }

    auto &ret = mem[idx] ; 
    if(ret != -1){
        return ret ;
    }
    ret = 0; 

    for(int j = idx+1 ; j < (int)numList.size() ;++j){
        if(numList[j] > numList[idx]){
            ret = max(ret , LIS(j));
        }
    }
    ret +=1 ; 
    return ret ;
    
}

// Version 1
int LengthofLIS(const vector<int> &nums){
    memset(mem,-1,sizeof(mem)) ; 

    numList = nums ; 
    numList.insert(numList.begin() , INT_MIN) ; // A Trick to make sure that this position will be always corrent, so no need for a loop
    return LIS(0)-1 ; 
}

// Version 2 
int __LengthofLIS(const vector<int> &nums){
    memset(mem , -1 , sizeof(mem)) ;
    numList = nums;
    int ret = 0 ; 

    for(int j = 0 ; j < (int)numList.size() ; ++j){
        int start = LIS(j) ; 
        ret = max(ret , start) ;
    }
    return ret ; 
}