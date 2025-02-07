class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        map<int, int> mp, cntr;
        vector<int> ans;
        for (auto k : q) {
            int i = k[0], j = k[1];
            if (mp[i]) {
                cntr[mp[i]]--;
                if (cntr[mp[i]] == 0) {
                    cntr.erase(mp[i]);
                    cout << mp[i] << " " << cntr.size() << endl;
                }
            }
            mp[i] = j;
            cntr[j]++;
            ans.push_back(cntr.size());
        }
        return ans;
    }
};