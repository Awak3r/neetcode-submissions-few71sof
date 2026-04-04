class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int n1 = 0; n1 < nums.size(); n1++){
            for (int n2 = n1 + 1; n2 < nums.size(); n2++){
                if (nums[n1] + nums[n2] == target && n1 != n2){
                    return {n1, n2};
                }
            }
        }
    }
};
