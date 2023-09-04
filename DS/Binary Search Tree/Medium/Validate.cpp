/*
=====================
    Medium Problem 
    Problem#1
=====================
    Leetcode <https://leetcode.com/problems/validate-binary-search-tree/>
*/

#include "../Bst.hpp"

bool solve(TreeNode* root , long long  lb   , long long  ub){
        if(!root)
            return true ; 
        if((root->val < ub && root->val > lb)&&(solve(root->left , lb,root->val))&&(solve(root->right , root->val , ub))){
            return true; 
        }else{
            return false ;
        }
}
bool isValidBST(TreeNode* root) {
        long long  lb = LLONG_MIN ; 
        long long  ub = LLONG_MAX ; 
        bool ans = solve(root , lb , ub) ; 
        return ans ;
}