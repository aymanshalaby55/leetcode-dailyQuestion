class Solution {
public:
    bool isvowel(char s) {
        return (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u');
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> pref(words.size() + 1);
        if (isvowel(words[0][0]) && isvowel(words[0][words[0].size() - 1])) {
            pref[0] = 1;
        }
        cout << pref[0] << " ";
        for (int i = 1; i < words.size(); i++) {
            if (isvowel(words[i][0]) &&
                isvowel(words[i][words[i].size() - 1])) {
                pref[i] += pref[i - 1] + 1;
            } else {
                pref[i] += pref[i - 1];
            }
            cout << pref[i] << " ";
        }
        pref[words.size()] = pref[words.size() - 1];
        vector<int> ans;
        for (auto i : queries) {
                ans.push_back(pref[i[1]] - (i[0] != 0?pref[i[0] - 1]:0));
        }

        return ans;
    }
};