class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_r = 0;
        int l = 0, r = 1;
        while(r < prices.size()){
            if (prices[l] < prices[r]){
                int cur  = prices[r] - prices[l];
                max_r = max(max_r, cur);
            } else {
                l = r;
            }
            r+=1;
        }
        return max_r;
    }
};
