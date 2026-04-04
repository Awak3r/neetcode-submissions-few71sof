class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ll;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size() - 1; k++){
            int l = 0;
            int r = nums.size() - 1; 
            while(l < k && k < r) {
                if (nums[l] + nums[k] + nums[r] == 0){
                    vector<int> cur_v = {nums[l], nums[k], nums[r]};
                    if(find(ll.begin(), ll.end(), cur_v) == ll.end()){
                        ll.push_back(cur_v);
                    }
                    l++;
                }
                else if (nums[l] + nums[k] + nums[r] < 0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        vector<vector<int>> res;
        for(auto& cur: ll){
            res.push_back(cur);
        }
        return res;
    }
};
