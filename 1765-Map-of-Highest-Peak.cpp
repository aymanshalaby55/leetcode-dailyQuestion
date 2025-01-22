class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool isValidCell(int x, int y, int rows, int columns) {
        return x >= 0 && y >= 0 && x < rows && y < columns;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> q;
        int n = isWater.size(), m = isWater[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    isWater[i][j] = 0;
                } else {
                    isWater[i][j] = -1; // must be less than water
                }
            }
        }
        int firstLevel = 1;
        while (!q.empty()) {
            int layerSize = q.size();
            for (int u = 0; u < layerSize; u++) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int x1 = x + dx[i];
                    int y1 = y + dy[i];
                    if (isValidCell(x1, y1, n, m) && isWater[x1][y1] == -1) {
                        isWater[x1][y1] = firstLevel;
                        q.push({x1, y1});
                    }
                }
            }

            firstLevel++;
        }
        return isWater;
    }
};