class Solution {
public:
    void backtrack(int i, vector<int>& nums, vector<vector<int>>& ans, int target, vector<int>& st) {
        if(!target) { ans.push_back(st); return;}
        if(i >= nums.size() || target < 0 || nums[i] > target) return;
        st.push_back(nums[i]);
        backtrack(i, nums, ans, target - nums[i], st);
        st.pop_back();
        backtrack(i + 1, nums, ans, target, st);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> st;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, ans, target, st);
        return ans;
    }
};
