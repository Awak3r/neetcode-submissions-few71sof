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
    void dfs(TreeNode* root, vector<bool>& value, int depth, vector<int>& res){
        if (!root) return;
        if (value[depth] == false) {
            res.push_back(root->val); 
            value[depth] = true;
        }
        dfs(root->right, value, depth + 1, res);
        dfs(root->left, value, depth + 1, res);

    }

    vector<int> rightSideView(TreeNode* root) {
        vector<bool> value(100, false);
        vector<int> res;
        dfs(root, value, 0, res);
        return res;
    }
};
