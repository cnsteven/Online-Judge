/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

#include "main.h"
// @lc code=start
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        while (root) {
            if (p->val < root->val && q->val < root->val)
                root = root->left;
            else if (p->val > root->val && q->val > root->val)
                root = root->right;
            else
                break;
        }
        return root;
    }
};
// @lc code=end
