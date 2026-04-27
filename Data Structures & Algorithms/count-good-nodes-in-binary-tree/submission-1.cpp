/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* root, int& res, int maxic){
        if (!root) return;
        if (root->val >= maxic) res++;
        dfs(root->left, res, max(maxic, root->val));
        dfs(root->right, res, max(maxic, root->val));

    }
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, res, -INT_MAX);
        return res;
    }
};
