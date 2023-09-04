#include "../Bst.hpp"
/*
    Leetcode Easy (Problem #1)
    Link <https://leetcode.com/problems/search-in-a-binary-search-tree/description/>
*/
TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return nullptr; 
        int value  = root->val ; 

        if(value  == val){
            return root ; 
        }else if (val < value){
            return searchBST(root->left , val) ; 
        }else{
            return searchBST(root->right , val) ; 
        }
        return root ; 
    }