#ifndef _BST_
#define _BST_

#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>
#include<utility>
struct TreeNode{
    int val {} ; 
    TreeNode *left { } ; 
    TreeNode *right { } ; 

    TreeNode(int data): val(data) {}
} ; 

class BST{
    private: 
        TreeNode *root { } ; 
       void  deleteTree(TreeNode *root) ; 
       TreeNode *insert(TreeNode *root , int val) ; 
       void inorder_print(TreeNode *root) ;
       std::pair <TreeNode * , bool>search(TreeNode *root , int target);

   public:
       BST();
       BST(int data);
       ~BST();
       void insert(int target);
       void print(); 
        bool search(int target){
            //TODO: Fix pair search
            if(std::pair<TreeNode* , bool>search(root,target)) return true ; 
            return false ;  
        }
}; 

#endif