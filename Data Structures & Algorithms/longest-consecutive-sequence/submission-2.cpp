class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int max_len = 0;
        int cur_len, cur_cur;
        for(auto& cur: numSet){
            if (numSet.find(cur - 1) == numSet.end()){
                cur_len = 1;
                cur_cur = cur + 1;
                while(numSet.find(cur_cur) != numSet.end()){
                    cur_len +=1;
                    cur_cur++;
                }
                if (max_len < cur_len){
                    max_len = cur_len;
                }
            }
        }
        return max_len;
    }
};
