/*
    LeetCode : <https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/>
*/

#include"../Bst.hpp"
#include <vector>

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if(nums.size() == 0)return NULL ; 
        if(nums.size() == 1)return new TreeNode(nums[0]) ; 
      
        // Index of the middle of the vector to start as a root
        int med = nums.size() /2 ; 
        //Sorted Array, so we can split it into to arrays for the left and the right.

        std::vector<int>left (nums.begin() , nums.begin()+med) ;
        std::vector<int>right  (nums.begin()+med+1 , nums.end()) ; 
        TreeNode* root = new TreeNode(nums[med]) ; 
        root->left = sortedArrayToBST(left) ; 
        root->right = sortedArrayToBST(right) ;  
        return root  ;
}