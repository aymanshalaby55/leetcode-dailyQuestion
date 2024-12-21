class Solution {
public:
    map<int, bool> visited;
    vector<vector<int>> adj;
    int ans = 0;
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {

        adj.resize(n);
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        dfs(0, k, values);

        return ans;
    }

    long long dfs(int value, int k, vector<int>& values) {
        visited[value] = true;
        long long sum = 0;
        for (auto i : adj[value]) {
            if (!visited[i]) {
                sum += dfs(i, k, values);
                sum %= k;
            }
        }

        sum += values[value];
        sum %= k;
        if (sum == 0)
            ans++;
        return sum;
    }
};