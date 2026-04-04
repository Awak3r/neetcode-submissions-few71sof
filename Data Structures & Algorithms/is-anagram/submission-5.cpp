class Solution {
public:
    bool isAnagram(string s, string t) {
        int m1 = s.size();
        int m2 = t.size();
        std::unordered_map<char, int> l1;
        std::unordered_map<char, int> l2;
        if (m1 != m2) {return false;}
        for (char s_cur: s){
            l1[s_cur]++;
        }
        for (char t_cur: t){
            l2[t_cur]++;
        }
        for (auto& x: l1){
            if (x.second != l2[x.first]){
                return false;
            }
        }
        return true;
    }   
};
