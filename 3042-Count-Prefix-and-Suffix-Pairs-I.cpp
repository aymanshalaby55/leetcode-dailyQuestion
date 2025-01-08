class Solution {
public:
    bool isPrefixSuffix(string s, string c) {
        return c.find(s) == 0 && c.rfind(s) == c.size() - s.size();
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cntr = 0, n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[i].size() <= words[j].size())
                    cntr += isPrefixSuffix(words[i], words[j]);
            }
        }
        return cntr;
    }
};