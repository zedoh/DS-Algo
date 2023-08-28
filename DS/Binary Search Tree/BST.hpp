#ifndef _BST_
#define _BST_

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <utility>
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
       void insert(TreeNode *root , int val) ; 
       void inorder_print(TreeNode *root) ;
       std::pair <TreeNode * , bool>search(TreeNode *root , int target);
       void link(TreeNode* parent , TreeNode* child , const std::string& directoin) ; 
       bool IsLeaf(TreeNode *node) ; 
       TreeNode *GetParent(TreeNode *root  , TreeNode* ToDelete) ; 
       TreeNode *GetLeaf(TreeNode *root , const std::string &direction) ;
       std::vector<int> BstToVec(TreeNode *root);

       /*------------------Debuging Utilities--------------------*/
       std::vector<int>DebugSorted(std::vector<int>&v) ; 
       bool DebugCheckTree(std::vector<int>&v) ; // Debugging purposes 

   public:
       BST();
       BST(int data);
       ~BST();
       void insert(int target);
       void print();
       bool search(int target);
       void Delete(int target);
       bool CheckTree() ; 
    
}; 

#endif