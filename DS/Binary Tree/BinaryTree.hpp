#ifndef _BINARYTREE_
#define _BINARYTREE_
#include <iostream>
#include <vector>
#include <cassert>
#include<cmath>

struct TreeNode {
    int data {} ; 
    TreeNode *left{ } ; 
    TreeNode *right{ } ;

    TreeNode(int value):data(value) {}
}; 

class BinaryTree{
    private:
        TreeNode *root{ } ; 
        
        void delete_tree(TreeNode *node){
            if(!node) return ; 
                delete_tree(node->right) ; 
                delete_tree(node->left) ; 
                delete node;
            }

        void _print_inorder(TreeNode *node){
            if(!node) return ; 
           _print_inorder(node->left) ; 
            std::cout<<node->data<<'\t' ;
            _print_inorder(node->right) ;          
        }

        int TreeMax(TreeNode *curr){
            if(!curr) return 0;
            int mx = curr->data ; 
            if(root->left) {
                mx = std::max(mx,TreeMax(curr->left)) ; 
            }
            if(root->right){
                mx = std::max(mx,TreeMax(curr->right)) ; 
            }
            return mx ; 
        }

        int nodes(TreeNode *node){ //Number of Nodes in the Tree , 1-Based
            if(!node) return 0 ; 
            return 1+nodes(node->right)+nodes(node->left) ;
        }

        int levels(TreeNode *node){ // How many levels is the tree ? Zero-based 
            if(!node) return 0 ; 
           int  LeftTree = levels(node->left) ; 
            int RightTree = levels(node->right) ; 

            return 1+std::max(LeftTree,RightTree) ; 
        }

        bool is_perfect(TreeNode *root){
            if(!root) return 0 ; 
            int lvls = levels(root) ; 
            int sum{0} ;
            while(lvls--){
                sum+=std::pow(2,lvls) ; 
            }
            return sum == nodes(root) ; 
        }
        //Leet code solutions goes here !!
        class LeetCodeSolutions{
            public:
                int _MaxDepth(TreeNode *root)
                {
                    if (!root)
                        return 0;
                    return 1 + std::max(_MaxDepth(root->right), _MaxDepth(root->left));
                }

                bool TreeSearch(TreeNode *node, int CurrSum, int TargetSum)
                {
                    if (!node)
                        return false;
                    CurrSum += node->data;
                    if (!node->right && !node->left)
                    {
                        return CurrSum == TargetSum;
                    }
                    return (TreeSearch(node->right, CurrSum, TargetSum)) || (TreeSearch(node->left, CurrSum, TargetSum));
                }

                bool hasPathSum(TreeNode *root, int targetSum)
                {
                    return TreeSearch(root, 0, targetSum);
                }
        };
        
        LeetCodeSolutions sol;

    public:
        BinaryTree(int rootValue) : root(new TreeNode(rootValue)) {}
        ~BinaryTree(){
            TreeNode *curr = root;
            delete_tree(curr);
        }

        void add(std::vector<int> values  , std::vector<char>dir){
            assert(values.size() == dir.size())  ; 
            TreeNode *curr = this->root;
            for(int i = 0 ; i< (int)values.size() ; ++i){
                if(dir[i] == 'L'){
                    if(!curr->left)
                        curr->left = new TreeNode(values[i]) ; 
                    else
                        assert(curr->left->data == values[i]) ; 
                    curr = curr->left ; 
                }
                else{
                    if(!curr->right)
                        curr->right = new TreeNode(values[i]) ; 
                    else  
                        assert(curr->right->data == values[i]) ; 
                    curr=curr->right ; 
                }
            }
        }

        void print_inorder(){
            _print_inorder(root) ; 
            std::cout<<'\n' ; 
        }

        int MaxValue(){
            return TreeMax(root) ; 
        }

        int MaxDepth(){
            return sol._MaxDepth(root)  ;
        }

        int Nodes(){ //Number of nodes
            return nodes(root)  ; 
        }

        bool IsPerfect(){ //Is is it a perfect tree ?
            return is_perfect(root) ; 
        }
        
        int TreeLevels() // Number of tree levels
        {
            return levels(root) ; 
        }

}; 
  
#endif