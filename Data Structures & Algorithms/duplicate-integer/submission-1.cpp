class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> nums2;
        for(int i = 0; i < nums.size(); i++){
            if (nums2.find(nums[i]) != nums2.end()){
                return true;
            }
            else{
                nums2.insert(nums[i]);
            }
        }
        return false;
    }
};