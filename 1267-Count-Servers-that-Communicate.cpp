class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;

        vector<int> row_counts(m, 0);
        vector<int> col_counts(n, 0);

        // Calculate row counts
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row_counts[i] += grid[i][j];
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                col_counts[j] += grid[i][j];
            }
        }

        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 &&
                    (row_counts[i] > 1 || col_counts[j] > 1)) {
                    count++;
                }
            }
        }

        return count;
    }
};