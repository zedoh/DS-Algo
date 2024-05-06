vector<vector<char>> grid ; 
class Solution {
public:
    int rows , cols ; 
    int mem[301][301] ; 
    int squares(int r , int c){
        if( r >= rows || c >= cols || grid[r][c] == '0') return 0 ; 
        auto &ret = mem[r][c] ; 
        if(ret != -1)
            return ret ;

        int right = squares(r , c+1) ; 
        int down = squares(r+1 , c) ; 
        int downright = squares(r+1 , c+1) ; 
        return ret = 1 + min(min(right,down),downright) ; 
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        grid = matrix ; 
        memset(mem, -1 ,sizeof(mem)) ; 
        rows = grid.size() ; 
        cols = grid[0].size() ; 
        int mn  = INT_MIN ; 
        for(int i = 0 ; i < (int)grid.size() ; ++i){
            for(int j = 0 ; j  < cols ; ++j){
                mn = max(mn,squares(i , j))  ; 
            }
        }

        return mn*mn ; 
    }
};