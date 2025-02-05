class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cntr = 0;
        map<int, int> mp;
        for (int i = 0; i < s1.size(); i++) {
            cntr += s1[i] != s2[i];
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return cntr <= 2 && s1 == s2;
    }
};