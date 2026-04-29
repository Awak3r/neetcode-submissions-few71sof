class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s_len = s1.size();
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        unordered_set<char> ss;
        for(int i = 0; i < s_len; i++){
            m1[s1[i]]++;
            m2[s1[i]] = 0;
            ss.insert(s1[i]);
        }
        int cur_len = 0;
        int l = 0;
        for(int i = 0; i < s2.size(); i++){
            if (ss.find(s2[i]) == ss.end()){
                l = i + 1;
                cur_len = 0;
                for (auto& [key, value] : m2) {
                    value = 0;
                }
                continue;
            }
            m2[s2[i]]++;
            cur_len++;
            while (cur_len > s_len){
                m2[s2[l]]--;
                l++;
                cur_len--;
            }
            if(m1 == m2) return true;
        }        
        return false;
    }
};
