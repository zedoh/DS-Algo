string word;
class Solution {
public:
    string word;
    int mem[501][501] ;  
    int minPalindrome(int start , int end){
        if(start >= end)    return 0 ; 
        auto &ret  = mem[start][end] ; 
        if(~ret)    return ret ;
        if(word[start] == word[end]){
            ret = minPalindrome(start+1 , end-1) ; 
        }else{
            int choice1 = 1 + minPalindrome(start+1 , end) ; 
            int choice2 = 1 + minPalindrome(start, end-1) ; 
            ret = min(choice1 , choice2) ; 
        }
        return ret ;
    }


    int minInsertions(string s) {
        word = s ; 
        memset(mem , -1 , sizeof(mem)) ; 
        int size = word.size()-1 ;
        return minPalindrome(0 , size) ; 
    }
};