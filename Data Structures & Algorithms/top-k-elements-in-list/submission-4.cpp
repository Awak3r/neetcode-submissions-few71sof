#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> ll;
        for (int& cur : nums) {
            ll[cur]++;
        }
        vector<pair<int, int>> freq_pairs;
        for (auto& cur : ll) {
            freq_pairs.push_back(cur);
        }
        sort(freq_pairs.begin(), freq_pairs.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });
        for (int i = 0; i < k; i++) {
            res.push_back(freq_pairs[i].first);
        }

        return res;
    }
};