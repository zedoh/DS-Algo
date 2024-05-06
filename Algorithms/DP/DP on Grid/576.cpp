class Solution {
public:
    int ms , ns , moves ; 
    int mem[51][51][51] ;
    int MOD {1000000007} ;  
    int moveBall(int r , int c , int moves){
        if(moves < 0) return 0 ;
        if(r >= ms || c >= ns || r < 0 || c < 0) return 1 ; 

        auto &ret = mem[r][c][moves] ; 
        if(ret != -1)
            return ret;

        // We need to apply a  move in 4 directions 
        ret = 0 ;
        ret += moveBall(r , c-1 , moves-1) ; 
        ret %= MOD ;
        ret += moveBall(r+1 , c , moves-1) ; 
        ret %= MOD ;
        ret+= moveBall(r , c+1 , moves-1) ; 
        ret %= MOD ; 
        ret += moveBall(r-1 , c, moves-1) ; 
        ret %= MOD ; 

        return ret ;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(mem , -1 , sizeof(mem)) ; 
        ms = m  ; 
        ns = n ;
        return moveBall(startRow,startColumn,maxMove) ; 
    }
};