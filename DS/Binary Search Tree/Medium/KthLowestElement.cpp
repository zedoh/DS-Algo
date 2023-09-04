/*
Medium Problem
Problem No.2

LeetCode <https://leetcode.com/problems/kth-smallest-element-in-a-bst/>

*/

#include "../Bst.hpp"
#include <vector>

std::vector<int> VectorToInt(TreeNode *root)
{
    std::vector<int> nums;
    if (!root)
    {
        return nums;
    }

    // Recursively add elements from the left subtree
    std::vector<int> left = VectorToInt(root->left);
    nums.insert(nums.end(), left.begin(), left.end());

    // Add the current node's value
    nums.push_back(root->val);

    // Recursively add elements from the right subtree
    std::vector<int> right = VectorToInt(root->right);
    nums.insert(nums.end(), right.begin(), right.end());

    return nums;
}

int kthSmallest(TreeNode *root, int k)
{
    std::vector<int> answer = VectorToInt(root);
    return answer[k - 1];
}