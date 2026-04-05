#include <algorithm>
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int max_h = 0;
        while (l < r){
            max_h = max(max_h, (r - l) * min(heights[l], heights[r]));
            if (heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return max_h;
    }
};
