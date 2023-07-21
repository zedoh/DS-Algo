#ifndef _BINARYTREE_
#define _BINARYTREE_
#include <iostream>
#include <vector>
#include <cassert>

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
            print_inorder(node->right) ; 
            std::cout<<node->data<<'\t' ;
            print_inorder(node->left) ;  
        }

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

}; 
  
#endif