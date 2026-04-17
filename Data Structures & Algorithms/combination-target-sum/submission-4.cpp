class Solution {
public:
    int target;
    set<vector<int>> ans;
    vector<int> nums;
    void backtracking(vector<int>& path, int sum, int ind){
        if (sum > target) return;
        if (sum == target){
            vector<int> tmp = path;
            ans.insert(tmp);
            return;
        }
        for(int cur = ind; cur < nums.size(); cur++){
            path.push_back(nums[cur]);
            backtracking(path, sum + nums[cur], ind++);
            path.pop_back();
            backtracking(path, sum, ind + 1);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int t) {
        this->nums = nums;
        target = t;
        vector<int> soso;
        backtracking(soso, 0, 0);
        vector<vector<int>> res;
        for(vector<int> cur: ans){
            res.push_back(cur);
        }
        return res;
    }
};
