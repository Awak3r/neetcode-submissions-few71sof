class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        m = {}
        for i in range(len(strs)):
            l = {}
            for j in range(len(strs[i])):
                if strs[i][j] in l.keys():
                    l[strs[i][j]] += 1
                else:
                    l[strs[i][j]] = 1
            l_s = dict(sorted(l.items()))
            m[i] = l_s
        res = []
        for i in range(len(m)):
            if m[i] != -1:
                r = [strs[i]]
                for j in range(i + 1, len(m)):
                    if m[i] == m[j]:
                        r.append(strs[j])
                        m[j] = -1
                res.append(r)
        return res
