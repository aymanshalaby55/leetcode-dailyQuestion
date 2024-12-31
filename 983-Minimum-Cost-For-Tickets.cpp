class Solution {
public:
    vector<int> dp;
    map<int, int> values;
    int getMin(vector<int>& days, vector<int>& costs, int pass) {
        if (pass > days[days.size() - 1])
            return 0;

        if (dp[pass] != -1) {
            return dp[pass];
        }
        if (values[pass] != 1) {
            return getMin(days, costs, pass + 1);
        }
        int day1 = getMin(days, costs, pass + 1) + costs[0];
        int day7 = getMin(days, costs, pass + 7) + costs[1];
        int day30 = getMin(days, costs, pass + 30) + costs[2];

        return dp[pass] = min({day1, day7, day30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp = vector<int>(366, -1);
        for (auto i : days)
            values[i] = 1;
        return getMin(days, costs, 0);
    }
};