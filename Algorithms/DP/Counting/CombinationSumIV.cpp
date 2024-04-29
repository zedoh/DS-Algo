vector<int>numlist; 
class Solution {
public:
    int mem[5001] ; 
    int combine(int target){
      
        if(target < 0)
            return 0 ; 
        if(target == 0)
            return 1 ;
        auto &ret  = mem[target] ; 
        if(ret != -1)
            return ret ;
          
        ret = 0 ; 
        for(int i  = 0 ; i < (int)numlist.size() ; ++i){
            ret += combine(target-numlist[i]) ;     
        }

        return ret ;
    }
    int combinationSum4(vector<int>& nums, int target) {
        numlist = nums ;
        memset(mem , -1 , sizeof(mem)) ; 
        
        return combine(target);
    }
};