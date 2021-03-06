/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    int sum = 0;

    TreeNode *convertBST(TreeNode *root) {
        if (root) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};
// @lc code=end
