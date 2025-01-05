class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> pref(s.length() + 1, 0);

        for (auto i : shifts) {
            int start = i[0], end = i[1], direction = i[2];
            if (direction == 1) {
                pref[start] += 1;
                pref[end + 1] -= 1;
            } else {
                pref[start] -= 1;
                pref[end + 1] += 1;
            }
        }
        for (int i = 1; i < s.size(); i++) {
            pref[i] += pref[i - 1];
            pref[i] %= 26;
        }
        pref[0] %= 26;
        for (int i = 0; i < pref.size() - 1; i++) {
            int place = s[i] - 'a';
            int direc = pref[i];
            cout << pref[i] << " " << s[i] << endl;

            if (direc >= 0) {
                if (pref[i] + place > 25) {
                    pref[i] -= ('z' - 'a') - place + 1;
                    s[i] = 'a' + pref[i];
                } else {
                    s[i] += pref[i];
                }
            } else {
                if (pref[i] + place < 0) {
                    pref[i] += place + 1;
                    s[i] = 'z' + pref[i];
                } else {
                    s[i] += pref[i];
                }
            }
        }
        return s;
    }
};