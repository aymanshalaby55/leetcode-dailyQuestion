class Solution {
public:
    vector<int> dp;
    int find(int i, vector<int>& a) {
        if (i >= a.size() - 1)
            return 0;
        if (dp[i] != 10001) {
            return dp[i];
        }
        for (int j = 1; j <= a[i]; j++) {
            dp[i] = min(dp[i], find(j + i, a) + 1);
        }
        return dp[i];
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size() , 10001);
        cout << dp[0] << endl;
        return find(0, nums);
    }
};