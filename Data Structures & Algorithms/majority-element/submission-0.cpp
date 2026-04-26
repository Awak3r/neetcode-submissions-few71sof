class Solution {
public:
    int majorityElement(vector<int>& v) {
        int candidate = 0;
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (count == 0) {
                candidate = v[i];
            }
            if (v[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};