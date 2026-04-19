class Solution {
public:
    void dfs(TreeNode* p1, TreeNode* p2, bool& flag) {
        if (!p1 && !p2) return;
        if (!p1 || !p2) {
            flag = false;
            return;
        }
        if (p1->val != p2->val) {
            flag = false;
            return;
        }
        dfs(p1->left, p2->left, flag);
        dfs(p1->right, p2->right, flag);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool f = true;
        dfs(p, q, f);
        return f;
    }
};