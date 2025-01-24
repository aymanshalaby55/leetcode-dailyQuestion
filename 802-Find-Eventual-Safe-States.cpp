class Solution {
public:
    vector<int> in;
    vector<vector<int>> buildAdj(int n, vector<vector<int>>& graph) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (auto j : graph[i]) {
                adj[j].push_back(i);
                in[i]++;
            }
        }
        return adj;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        in.resize(n, 0);
        auto adj = buildAdj(n, graph);
        queue<int> find;
        vector<int> ord;
        for (int i = 0; i < n; i++) {
            if (!in[i]) {
                find.push(i);
                ord.push_back(i);
            }
        }
        while (find.size()) {
            int top = find.front();
            find.pop();

            for (auto i : adj[top]) {
                in[i]--;
                if (!in[i]) {            find.push(i);

                    ord.push_back(i);
                }
            }
        }
        sort(ord.begin(), ord.end());
        return ord;
    }
};