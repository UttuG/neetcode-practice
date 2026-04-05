class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '0' || visited[i][j]) {
                    continue;
                }

                islands++;
                queue<pair<int,int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();

                    int x = curr.first;
                    int y = curr.second;

                    // left
                    if (x - 1 >= 0 && grid[x - 1][y] == '1' && !visited[x - 1][y]) {
                        visited[x - 1][y] = true;
                        q.push({x - 1, y});
                    }
                    // right
                    if (x + 1 < n && grid[x + 1][y] == '1' && !visited[x + 1][y]) {
                        visited[x + 1][y] = true;
                        q.push({x + 1, y});
                    }
                    // up
                    if (y - 1 >= 0 && grid[x][y - 1] == '1' && !visited[x][y - 1]) {
                        visited[x][y - 1] = true;
                        q.push({x, y - 1});
                    }
                    // down
                    if (y + 1 < m && grid[x][y + 1] == '1' && !visited[x][y + 1]) {
                        visited[x][y + 1] = true;
                        q.push({x, y + 1});
                    }
                }
            }
        }
        return islands;
    }
};
