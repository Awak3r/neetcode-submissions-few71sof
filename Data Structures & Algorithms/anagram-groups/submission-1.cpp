class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ll;
        vector<std::map<char, int>> all_map;

        for (auto cur : strs) {
            std::map<char, int> cur_map;
            for (char r : cur) {
                cur_map[r]++;
            }

            auto it = find(all_map.begin(), all_map.end(), cur_map);

            if (it != all_map.end()) {
                int idx = it - all_map.begin();
                ll[idx].push_back(cur);
            } else {
                all_map.push_back(cur_map);
                ll.push_back({cur});
            }
        }
        return ll;
    }
};