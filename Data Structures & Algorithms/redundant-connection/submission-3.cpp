class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        
        // Initialize each node to be its own parent
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        // Find with path compression
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        // Union operation
        auto unionSets = [&](int a, int b) {
            int rootA = find(a);
            int rootB = find(b);
            if (rootA == rootB) return false; // already connected → cycle detected
            parent[rootB] = rootA;  // union
            return true;
        };

        // Process edges
        for (auto& edge : edges) {
            if (!unionSets(edge[0], edge[1])) {
                // This edge creates a cycle
                return edge;
            }
        }

        return {}; // fallback, problem guarantees answer
    }
};
