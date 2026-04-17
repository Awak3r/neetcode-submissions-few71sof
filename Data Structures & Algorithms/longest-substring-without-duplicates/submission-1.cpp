#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> sett;
        int l = 0, r = 1;
        sett.insert(s[0]);
        if (s.size() == 0) return 0;
        size_t res = 1;
        while (r < s.size()){
            while(sett.find(s[r]) != sett.end()){
                sett.erase(s[l]);
                l++;
            }
            sett.insert(s[r]);
            res = max(res, sett.size());
            r++;
        }
        return res;
    }
};
