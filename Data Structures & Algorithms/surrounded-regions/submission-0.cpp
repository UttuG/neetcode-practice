class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;
        set<pair<int,int>> safe; // cells that should remain 'O'

        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        // Initialize queue and safe set with border 'O's
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.push({i,0}); safe.insert({i,0});
            }
            if (board[i][n-1] == 'O') {
                q.push({i,n-1}); safe.insert({i,n-1});
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                q.push({0,j}); safe.insert({0,j});
            }
            if (board[m-1][j] == 'O') {
                q.push({m-1,j}); safe.insert({m-1,j});
            }
        }

        // BFS to mark all 'O's connected to the border
        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();

            for (auto [dr,dc] : dir) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    board[nr][nc] == 'O' && !safe.count({nr,nc})) {
                    q.push({nr,nc});
                    safe.insert({nr,nc});
                }
            }
        }

        // Flip all 'O's not in safe set to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !safe.count({i,j})) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};