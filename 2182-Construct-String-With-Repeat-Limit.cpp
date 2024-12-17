class Solution {
public:
    string repeatLimitedString(string s, int rl) {
        map<char, int> mp;
        priority_queue<char> q;
        for (auto i : s) {
            mp[i]++;
        }
        int rest = 0;
        for (auto i : mp) {
            rest++;
            q.push(i.first);
        }
        string ans = "";
        while (!q.empty()) {
            char c = q.top();
            int n = mp[c];
            for (int i = 1; i <= n; i++) {
                if (i > rl) {
                    if(rest == 1){
                        mp[c] = 0;
                        break;
                    }
                    q.pop();
                    char c2 = q.top();
                    ans.push_back(c2);
                    cout << c2 << " " << i << endl;
                    mp[c2]--;
                    if (mp[c2] == 0 && !q.empty()) {
                        q.pop();
                        rest--;
                    }
                    q.push(c);
                    break;
                }
                mp[c]--;
                ans.push_back(c);
            }
            if (mp[c] == 0) {
                q.pop();
                rest--;
            }
        }
        return ans;
    }
};