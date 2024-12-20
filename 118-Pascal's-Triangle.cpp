class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> generate(int n) {
        ans.push_back({1});

        for (int i = 1; i < n; i++) {
            vector<int> newRow = {1};
            for (int j = 1; j < i; j++) {
                newRow.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
            }
            newRow.push_back(1);
            ans.push_back(newRow);
        }
        return ans;
    }
};