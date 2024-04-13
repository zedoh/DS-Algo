// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

const int MAX {1000} ; 
int memLIS[MAX] ; 
int memLDS[MAX] ; 
vector<int> numlist ;

// Longest increasing subsequence ending at the index `idx`
int LIS(int idx){
    if(idx == -1) return 0 ; 

    auto &ret = memLIS[idx] ; 
    if(ret != -1)   return ret ; 

    ret = 0 ; 
    for(int i = idx-1 ; i >= 0 ; --i){
        if(numlist[i] < numlist[idx])
            ret = max(ret , LIS(i)) ; 
    }

    ret += 1 ; 
    return ret ;
}


// Longest Decreasing Subsequence starting from the index `idx`
int LDS(int idx){
    if(idx == (int)numlist.size())  return 0 ; 

    auto &ret = memLDS[idx] ; 
    if(ret != -1)   return ret ;

    ret = 0 ; 
    for(int i = idx+1  ; i < (int)numlist.size() ; ++i){
        if(numlist[i] < numlist[idx]){
            ret = max(ret , LDS(i)) ; 
        }
    }

    ret += 1; 
    return ret ;
}

class Solution {
public:
    
    int minimumMountainRemovals(vector<int>& nums) {
        memset(memLIS , -1 , sizeof(memLIS)) ; 
        memset(memLDS , -1 , sizeof(memLDS)) ; 
        numlist = nums; 
        int size = numlist.size() ; 
        // if(size < 3)    return 0 ;

        int LongestMountain {0} ; 
        for(int i = 0 ; i < size ; ++i){
            if(LIS(i) ==  1 || LDS(i) == 1) {
                continue ;
            }
            int currentLongest = LIS(i) + LDS(i) - 1  ; 
            LongestMountain = max(currentLongest , LongestMountain)  ;  
        }

        return size - LongestMountain; // Minimum Removals
    }
};