#include <iostream>
#include <memory>
#include <vector>
#include <cstring>
#include <climits>
using namespace std ; 

string word1{"golang"} ; 
string word2{"language"}  ; 

const int MAX{2501} ; 
int mem[MAX][MAX] ; 

int LCS(int idx1 , int idx2){
    if(idx1 == word1.size()|| idx2 == word2.size()){
        return 0 ; 
    }
    auto &ret = mem[idx1][idx2] ; 
    if(ret != -1){
        return ret ; 
    }
    if(word1[idx1] == word2[idx2]){
        ret = 1+ LCS(idx1+1 , idx2+1);
     
    }else{
        int choice1 = LCS(idx1+1, idx2) ; 
        int choice2 = LCS(idx1,idx2+1) ; 
        ret = max(choice1,choice2) ; 
    }
    return ret;
}

int main(){
    memset(mem,-1,sizeof(mem))  ;
    cout<<LCS(0,0) <<'\n' ;     // 4 

}