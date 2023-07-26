#ifndef _LEETCODE_
#define _LEETCODE_
#include"BinaryTree.hpp"

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

#endif