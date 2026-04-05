class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        // special case: single node, no edges
        if (n == 1 && edges.empty()) return true;

        // if number of edges is not exactly n-1: return false
        if (edges.size() != n - 1){
            return false;
        }

        // set of nodes that are visited, to check loop
        set<int> visited;

        // make a node - adjacent nodes mapping in hashmap (adjacency list)
        unordered_map<int, vector<int>> adj;
        for (vector<int> p : edges) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);  // because the graph is undirected
        }

        // make BFS queue
        queue<pair<int,int>> tovisit;  // store {node, parent}
        int start = adj.begin()->first;   // pick one node
        tovisit.push({start, -1});
        visited.insert(start);  // mark start visited

        // while queue not empty
        while (!tovisit.empty()){
            auto [curr_node, parent] = tovisit.front();
            tovisit.pop();

            // check its neighbours
            for (int neighbor : adj[curr_node]){
                if (neighbor == parent) continue;  // skip edge back to parent
                if (visited.count(neighbor)) return false; // cycle detected
                visited.insert(neighbor);
                tovisit.push({neighbor, curr_node});
            }
        }

        // if visited set does not cover all nodes: return false
        if (visited.size() != n){
            return false;
        }

        // return true
        return true;
    }
};