class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> bfsqueue;

        // Step 1: Add all treasures (0s) to the queue
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {  // treasures, not INF
                    bfsqueue.push({i, j, 0});
                }
            }
        }

        set<tuple<int, int>> visited;

        // Step 2: Standard BFS
        while (!bfsqueue.empty()) {
            tuple<int, int, int> curr_node = bfsqueue.front();
            bfsqueue.pop();

            int row = get<0>(curr_node);
            int col = get<1>(curr_node);
            int level = get<2>(curr_node);

            vector<pair<int, int>> directions = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}
            };

            for (auto dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                if (newRow >= 0 && newRow < grid.size() &&
                    newCol >= 0 && newCol < grid[0].size()) {

                    tuple<int, int> neighbor = {newRow, newCol};

                    // Only update unvisited empty rooms (INF)
                    if (!visited.count(neighbor) && grid[newRow][newCol] == INT_MAX) {
                        visited.insert(neighbor);
                        grid[newRow][newCol] = level + 1;
                        bfsqueue.push({newRow, newCol, level + 1});
                    }
                }
            }
        }
    }
};
