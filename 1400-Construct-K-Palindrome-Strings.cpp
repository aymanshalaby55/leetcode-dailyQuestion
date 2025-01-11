class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k)
            return false;
        if (s.length() == k)
            return true;
        map<char, int> mp;
        int subnum = (int)s.size() / k;
        int even = 0, odd = 0;
        for (auto i : s) {
            mp[i]++;
        }
        for (auto i : mp) {
            (i.second & 1) ? odd++ : even++;
        }
        cout << subnum << endl;
        if (k < odd) {
            return false;
        }
        return true;
    }
};