class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<vector<int>> toupdateneighbours;

        int n = grid.size();
        int m = grid[0].size();

        // Add all treasures (0s) to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    toupdateneighbours.push({i, j});
                }
            }
        }

        while (!toupdateneighbours.empty()) {
            vector<int> curr = toupdateneighbours.front();
            toupdateneighbours.pop();

            int r = curr[0];
            int c = curr[1];

            // left
            if (r > 0 && grid[r - 1][c] == INT_MAX) {
                grid[r - 1][c] = grid[r][c] + 1;
                toupdateneighbours.push({r - 1, c});
            }

            // right
            if (r < n - 1 && grid[r + 1][c] == INT_MAX) {
                grid[r + 1][c] = grid[r][c] + 1;
                toupdateneighbours.push({r + 1, c});
            }

            // up
            if (c > 0 && grid[r][c - 1] == INT_MAX) {
                grid[r][c - 1] = grid[r][c] + 1;
                toupdateneighbours.push({r, c - 1});
            }

            // down
            if (c < m - 1 && grid[r][c + 1] == INT_MAX) {
                grid[r][c + 1] = grid[r][c] + 1;
                toupdateneighbours.push({r, c + 1});
            }
        }
    }
};
