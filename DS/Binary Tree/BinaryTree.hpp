#ifndef _BINARYTREE_
#define _BINARYTREE_
#include <iostream>
#include<string>
#include <vector>
#include <queue>
#include <cassert>
#include <cmath>

struct TreeNode
{
    int val{};
    TreeNode *left{};
    TreeNode *right{};

    TreeNode(int value) : val(value) {}
};

class BinaryTree
{
private:
    TreeNode *root{};

    void delete_tree(TreeNode *node)
    {
        if (!node)
            return;
        delete_tree(node->right);
        delete_tree(node->left);
        delete node;
    }

    void _print_inorder(TreeNode *node)
    {
        if (!node)
            return;
        _print_inorder(node->left);
        std::cout << node->val << '\t';
        _print_inorder(node->right);
    }

    int TreeMax(TreeNode *curr)
    {
        if (!curr)
            return 0;
        int mx = curr->val;
        if (root->left)
        {
            mx = std::max(mx, TreeMax(curr->left));
        }
        if (root->right)
        {
            mx = std::max(mx, TreeMax(curr->right));
        }
        return mx;
    }

    int nodes(TreeNode *node) 
    { // Number of Nodes in the Tree , 1-Based
        if (!node)
            return 0;
        return 1 + nodes(node->right) + nodes(node->left);
    }

    int levels(TreeNode *node)
    { // How many levels is the tree ? Zero-based
        if (!node)
            return 0;
        int LeftTree = levels(node->left);
        int RightTree = levels(node->right);

        return 1 + std::max(LeftTree, RightTree);
    }

    bool is_perfect(TreeNode *root)
    {
        if (!root)
            return 0;
        int lvls = levels(root);
        int sum{0};
        while (lvls--)
        {
            sum += std::pow(2, lvls);
        }
        return sum == nodes(root);
    }
    
    class LeetCodeSolutions
    {
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
            CurrSum += node->val;
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

        std::vector<std::vector<int>> answer;

        int SumOfTree(TreeNode *node)
        {
            if (!node)
                return 0;
            int sum = node->val;
            sum += SumOfTree(node->right);
            sum += SumOfTree(node->left);
            return sum;
        }

        
    };
    LeetCodeSolutions sol;

public:
    BinaryTree(int rootValue) : root(new TreeNode(rootValue)) {}
    ~BinaryTree()
    {
        TreeNode *curr = root;
        delete_tree(curr);
    }

    void add(std::vector<int> values, std::vector<char> dir)
    {
        assert(values.size() == dir.size());
        TreeNode *curr = this->root;
        for (int i = 0; i < (int)values.size(); ++i)
        {
            if (dir[i] == 'L')
            {
                if (!curr->left)
                    curr->left = new TreeNode(values[i]);
                else
                    assert(curr->left->val == values[i]);
                curr = curr->left;
            }
            else
            {
                if (!curr->right)
                    curr->right = new TreeNode(values[i]);
                else
                    assert(curr->right->val == values[i]);
                curr = curr->right;
            }
        }
    }

    void print_inorder()
    {
        _print_inorder(root);
        std::cout << '\n';
    }

    int MaxValue()
    {
        return TreeMax(root);
    }
    

    int MaxDepth()
    {
        return sol._MaxDepth(root);
    }

    int Nodes()
    { // Number of nodes
        return nodes(root);
    }

    bool IsPerfect()
    { // Is is it a perfect tree ?
        return is_perfect(root);
    }

    int TreeLevels() // Number of tree levels
    {
        return levels(root);
    }

    void LevelTraversal()
    {
        std::queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            TreeNode *curr = nodes.front();
            nodes.pop();
            std::cout << curr->val << '\t';
            if (curr->left)
            {
                nodes.push(curr->left);
            }
            if (curr->right)
            {
                nodes.push(curr->right);
            }
        }
        std::cout << '\n';
    }

    int SumofTheTree()
    {
        return sol.SumOfTree(root);
    }

    std::string  TreeParenth(TreeNode *root){
        if(!root) return "()"  ; 
        std::string rep = "("+std::to_string(root->val) ; 
        if(root->right){
            rep+=TreeParenth(root->right) ; 
        }else{
            rep+="()" ; 
        }
        
        if(root->left){
            rep+=TreeParenth(root->left) ; 
        }else{
            rep+="()" ; 
        }

        rep+=")" ; 

        return rep ; 
    }

    std::string TreeParenth(){
        return TreeParenth(root) ; 
    }

    std::string parenthesize_conical(TreeNode *root){
        if(!root) return "()"  ; 
        string rep = "("+std::to_string(root->val) ; 

    }
}; 

#endif