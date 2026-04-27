class Solution {
public:
    bool obhod(TreeNode* root, TreeNode* p, TreeNode* q, pair<bool, bool>& tt) {
        if (!root) return false;
        if (root == p) tt.first = true;
        if (root == q) tt.second = true;
        if (tt.first && tt.second) return true;
        obhod(root->left, p, q, tt);
        obhod(root->right, p, q, tt);
        return tt.first && tt.second;
    }
    TreeNode* finding(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        TreeNode* left = finding(root->left, p, q);
        if (left) return left;
        TreeNode* right = finding(root->right, p, q);
        if (right) return right;
        pair<bool, bool> tt = {false, false};
        if (obhod(root, p, q, tt)) return root;
        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return finding(root, p, q);
    }
};