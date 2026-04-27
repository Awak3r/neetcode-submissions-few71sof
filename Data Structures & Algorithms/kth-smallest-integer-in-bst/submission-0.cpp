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
    void dfs(TreeNode* root, int& counter, int& res, int k){
        if (!root) return;
        dfs(root->left, counter, res, k);
        if (++counter == k) {
            res = root->val;
            return;
        }
        dfs(root->right, counter, res, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res;
        int counter = 0;
        dfs(root, counter, res, k);
        return res;
    }
};
