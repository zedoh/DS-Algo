#include"BST.hpp"

using namespace std  ;


//----------EASY PROBLEMS---------------------//
//---------PROBLEM  1------------------------//
TreeNode *searchBST(TreeNode *root, int val)
{
    if (!root)
        return nullptr;
    if (root->val == val)
        return root;
    else
    {
        if (val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
    return root;
}

//--------------PROBLEM 2------------------------//
TreeNode* sortedArrayToBST(vector<int>& nums) {
        int sz = nums.size() ; 
        if(sz == 0 )return nullptr; 
        if (sz == 1) return new TreeNode(nums[0]) ; 
        int mid = sz / 2  ; 
        TreeNode* root = new TreeNode(nums[mid]) ; 
        vector<int> leftsub(nums.begin() , nums.begin()+mid) ; 
        vector<int> rightsub(nums.begin()+mid+1 , nums.end()) ; 
        root->left =  sortedArrayToBST(leftsub) ; 
        root->right = sortedArrayToBST(rightsub)  ;
        return root ;
}

/*-----------------------Medium Problems--------------------*/