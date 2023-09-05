#ifndef _BST_
#define _BST_

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <utility>
struct TreeNode {
    int val{};
    TreeNode* left{ };
    TreeNode* right{ };

    TreeNode(int data) : val(data) {}
    
};

class BST {

private:
    TreeNode* root{ };
    void  deleteTree(TreeNode* root);
    void insert(TreeNode* root, int val);
    void inorder_print(TreeNode* root);
    std::pair <TreeNode*, bool>search(TreeNode* root, int target);
    void link(TreeNode* parent, TreeNode* child, const std::string& directoin);
    bool IsLeaf(TreeNode* node);
    TreeNode* GetParent(TreeNode* root, TreeNode* ToDelete);
    bool findChain(TreeNode* root  ,int target, std::vector<TreeNode*>& anscestor); //Find the whole chain starting from the root to the target node.
    TreeNode* getLeaf(TreeNode* root , const std::string& direction); // leaf in the direction{right, left}. 
    TreeNode* getNext(std::vector<TreeNode*>& ancsector); 
    int minValue(TreeNode* root); 
    
    
    /*------------------Debuging Utilities--------------------*/
    std::vector<int> BstToVec(TreeNode* root);
    std::vector<int>DebugSorted(std::vector<int>& v);
    bool DebugCheckTree(std::vector<int>& v); // Debugging purposes 
    


public:
    BST() ;
    BST(int data);
    ~BST();
    void insert(int target);
    void print();
    bool search(int target);
    bool CheckTree();
    int minValue(); 
    int maxValue(); 
    int GetParent(int target); 
    int GetChild(int target, const std::string& direction); 

};


#endif