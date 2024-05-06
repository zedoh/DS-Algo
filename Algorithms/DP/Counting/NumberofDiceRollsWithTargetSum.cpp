class Solution {
public:
    int faces , dices ; 
    int limit = 1000000007 ; 
    int mem[31][1001] ; 
    int combination(int idx, int target){
        if(idx == dices && target == 0)  return 1 ; 
        if(idx == dices || target == 0) return 0 ; 
        if(target < 0)  return  0 ;

        auto &ret = mem[idx][target] ; 
        if(ret != -1)
            return ret; 

        ret = 0 ; 
        for(int i =1 ; i <= faces ; ++i){
            ret += combination(idx+1 , target-i);
            ret %= limit ; 
        }

        return ret; 
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(mem  , -1 , sizeof(mem)) ; 
        dices = n ; 
        faces = k ; 
        return combination(0 , target) ; 
    }
};