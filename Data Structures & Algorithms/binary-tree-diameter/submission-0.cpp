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
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int max_depth = 0;
        if (!root) return max_depth;
        q.push({root, 1});
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (cur->left) {
                TreeNode* left = cur->left;
                q.push({left, depth + 1});
            }
            else {
                max_depth = max(max_depth, depth);
            }

            if (cur->right) {
                TreeNode* right = cur->right;
                q.push({right, depth + 1});
            }
            else {
                max_depth = max(max_depth, depth);
            }
        }
        return max_depth;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
        int max_depth = 0;
        if (!root) return max_depth;
        q.push(root);
        while(!q.empty()){
           TreeNode* cur = q.front();
            q.pop();
            int d_cur =  maxDepth(cur->left) + maxDepth(cur->right);
            max_depth = max(d_cur, max_depth);
            if (cur->left) {
                TreeNode* left = cur->left;
                q.push(left);
            }
            if (cur->right) {
                TreeNode* right = cur->right;
                q.push(right);
            }
        }
        return max_depth;
    }
};
