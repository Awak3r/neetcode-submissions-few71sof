class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for (char c : t) {
            need[c]++;
        }
        int required = need.size();
        int formed = 0;
        int l = 0;
        int bestLen = INT_MAX;
        int bestL = 0;
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    formed++;
                }
            }
            while (formed == required) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestL = l;
                }
                char left = s[l];
                if (need.count(left)) {
                    window[left]--;
                    if (window[left] < need[left]) {
                        formed--;
                    }
                }
                l++;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
    }
};